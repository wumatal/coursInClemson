#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

void osInit(int width, int height, unsigned int flags, int *attribs);
void osQuit();
int osGetScreenWidth();
int osGetScreenHeight();
void osWaitVsync(int);
unsigned int osGetMilliseconds();
int osPollEvent(struct OS_EventRec *e);
void osSwapBuffers();
int osIsKeyDown(int);
int osShowCursor(int);

#ifdef WIN32
#include <windows.h>
void fatalf(const char *format, ...);
void debugf(const char *format, ...);
#else
#define fatalf(...) { fprintf(stderr, __VA_ARGS__); exit(1); }
#define debugf(...) { fprintf(stdout, __VA_ARGS__); }
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#include "GL/gl.h"
#include "GL/glext.h"

#define OSK_ESCAPE 0x1B
#define OSK_LEFT   0x25
#define OSK_RIGHT  0x27
#define OSK_SHIFT  0xA0
#define OSK_UP     0x26
#define OSK_DOWN   0x28

#define OSKS_UP 0
#define OSKS_DOWN 1

#define OS_BUTTON_LEFT 1
#define OS_BUTTON_MIDDLE 2
#define OS_BUTTON_RIGHT 3

#define OS_QUERY -1
#define OS_IGNORE 0
#define OS_DISABLE 0
#define OS_ENABLE 1
#define OS_FULLSCREEN  0x80000000
#define OS_RESIZABLE   0x00000010
#define OS_FSAA        0x00000020
#define OS_OVERLAY     0x00000040

typedef enum
{
   OS_NOEVENT,
   OS_KEYDOWN,
   OS_KEYUP,
   OS_MOUSEMOTION,
   OS_MOUSEBUTTONDOWN,
   OS_MOUSEBUTTONUP,
   OS_QUIT,
   OS_RESIZE,
} OS_EventType;

typedef struct OS_KeyboardEventRec
{
    unsigned char state;
    unsigned char key;
} OS_KeyboardEvent;

typedef struct OS_MouseEventRec
{
    unsigned char button;
    unsigned short x, y;
} OS_MouseEvent;

typedef struct OS_ResizeEventRec
{
    int width;
    int height;
} OS_ResizeEvent;

typedef struct OS_EventRec
{
    OS_EventType type;
    struct OS_EventRec *next;
    union
    {
        OS_KeyboardEvent key;
        OS_MouseEvent mouse;
        OS_ResizeEvent resize;
    };
} OS_Event;

typedef enum
{
    OS_GL_RED_SIZE,
    OS_GL_GREEN_SIZE,
    OS_GL_BLUE_SIZE,
    OS_GL_ALPHA_SIZE,
    OS_GL_BUFFER_SIZE,
    OS_GL_DOUBLEBUFFER,
    OS_GL_DEPTH_SIZE,
    OS_GL_STENCIL_SIZE,
    OS_GL_ACCUM_RED_SIZE,
    OS_GL_ACCUM_GREEN_SIZE,
    OS_GL_ACCUM_BLUE_SIZE,
    OS_GL_ACCUM_ALPHA_SIZE,
    OS_GL_STEREO,
    OS_GL_MULTISAMPLEBUFFERS,
    OS_GL_MULTISAMPLESAMPLES,
    OS_GL_ACCELERATED_VISUAL,
    OS_GL_SWAP_CONTROL
} OS_GLattr;

#ifdef __cplusplus
}
#endif
