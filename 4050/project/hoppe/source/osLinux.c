#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include <GL/glx.h>
#include <GL/glxext.h>
#include "os.h"

static Display *g_display;
static Window g_window;
static int g_screen;
static GLXContext g_context;

static OS_Event *g_eventHead = 0;
static OS_Event **g_eventTail = &g_eventHead;
static int g_keyboard[256];

void osInit(int width, int height, unsigned int flags, int *attribs)
{
    int attrib[] = {
        GLX_RGBA,
        GLX_DEPTH_SIZE, 16,
        GLX_RED_SIZE, 1,
        GLX_GREEN_SIZE, 1,
        GLX_BLUE_SIZE, 1,
        GLX_DOUBLEBUFFER, None,
    };

    XSetWindowAttributes attr;
    unsigned long mask;
    Window root;
    XVisualInfo *visinfo;

    atexit(osQuit);
    g_display = XOpenDisplay(NULL);
    g_screen = DefaultScreen(g_display);
    root = RootWindow(g_display, g_screen);
    visinfo = glXChooseVisual(g_display, g_screen, attrib);

    if (!visinfo)
    {
        printf("Error: couldn't create OpenGL window\n");
        exit(1);
    }

    attr.background_pixel = 0;
    attr.border_pixel = 0;
    attr.colormap = XCreateColormap(g_display, root, visinfo->visual, AllocNone);
    attr.event_mask = StructureNotifyMask | ExposureMask | KeyPressMask | KeyReleaseMask;
    mask = CWBackPixel | CWBorderPixel | CWColormap | CWEventMask;

    g_window = XCreateWindow(
        g_display,
        root,
        0, 0,
        width, height, 0,
        visinfo->depth,
        InputOutput,
        visinfo->visual,
        mask,
        &attr
    );

    XStoreName(g_display, g_window, "Hoppe Subdivision");

    g_context = glXCreateContext(g_display, visinfo, NULL, True);
    glXMakeCurrent(g_display, g_window, g_context);
    XMapWindow(g_display, g_window);
}

void osQuit(void)
{
    glXDestroyContext(g_display, g_context);
    XDestroyWindow(g_display, g_window);

    while (g_eventHead)
    {
        OS_Event *pending = g_eventHead;
        g_eventHead = pending->next;
        if (!g_eventHead)
            g_eventTail = &g_eventHead;
        free(pending);
    }

}

int osGetScreenWidth()
{
    return DisplayWidth(g_display, g_screen);
}

int osGetScreenHeight()
{
    return DisplayHeight(g_display, g_screen);
}

// http://opengl.org/registry/specs/SGI/swap_control.txt
void osWaitVsync(int interval)
{
    PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI;
    glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC) glXGetProcAddress((const GLubyte*) "glXSwapIntervalSGI");
    if (glXSwapIntervalSGI)
        glXSwapIntervalSGI(interval);
}

unsigned int osGetMilliseconds()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

int osPollEvent(struct OS_EventRec *e)
{
    if (XPending(g_display))
    {
        OS_Event e;
        XEvent event;
        e.type = OS_NOEVENT;

        XNextEvent(g_display, &event);
        switch (event.type)
        {
          case Expose:
            //redraw(g_display, event.xany.window);
            break;

          case ConfigureNotify:
            //resize(event.xconfigure.width, event.xconfigure.height);
            break;

          case KeyRelease:
          case KeyPress:
          {
            XComposeStatus composeStatus;
            char asciiCode[32];
            KeySym keySym;
            int len;

            if (event.type == KeyPress)
            {     
                e.type = OS_KEYDOWN;
                e.key.state = OSKS_DOWN;
            }
            else
            {
                e.type = OS_KEYUP;
                e.key.state = OSKS_UP;
            }

            // Check for the ASCII/KeySym codes associated with the event:
            len = XLookupString(&event.xkey, asciiCode, sizeof(asciiCode), &keySym, &composeStatus);

            // ASCII Key
            if (len > 0)
            {
                e.key.key = (unsigned char) asciiCode[0];
            }
            else // Special Key
            {
                switch (keySym)
                {
                  case OSK_LEFT:   e.key.key = OSK_LEFT;   break;
                  case OSK_RIGHT:  e.key.key = OSK_RIGHT;  break;
                  case OSK_UP:     e.key.key = OSK_UP;     break;
                  case OSK_DOWN:   e.key.key = OSK_DOWN;   break;
                }
            }

            // Update the keyboard state.
            g_keyboard[e.key.key] = e.key.state;
          }
          break;
        }

        if (e.type != OS_NOEVENT)
        {
            e.next = 0;
            *g_eventTail = (OS_Event*) malloc(sizeof(OS_Event));
            memcpy(*g_eventTail, &e, sizeof(OS_Event));
            g_eventTail = &((*g_eventTail)->next);
        }
    }

    if (g_eventHead)
    {
        OS_Event *pending = g_eventHead;
        memcpy(e, pending, sizeof(OS_Event));
        g_eventHead = pending->next;
        if (!g_eventHead)
            g_eventTail = &g_eventHead;
        free(pending);
        return 1;
    }
}

void osSwapBuffers()
{
    glXSwapBuffers(g_display, g_window);
}

int osIsKeyDown(int key)
{
    if (key < 0 || key > 0xff)
        return 0;

    return g_keyboard[key];
}

int osShowCursor(int) // TODO
{
    return 0;
}

