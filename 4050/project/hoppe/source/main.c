#include "os.h"
#include "mesh.h"

const float maxFPS = 60.0f;
Mesh g_mesh;

static void init()
{
    float yellow[] = {0.9f, 0.75f, 0, 0.5};
    float white[] = {1, 1, 1, 1};
    int lod;

    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 7.5f);

    glClearColor(1, 1, 1, 1);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glFrustum(-1, 1, -1, 1, 5, 10);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0, 0, -7.5f);

    //g_mesh = create_mesh("meshes/knot108s.nsub2.crep1e-5p.0.m");
    //g_mesh = create_mesh("meshes/mechpart.nsub2.0.m");
    //g_mesh = generate_icosahedron();
    g_mesh = generate_example(1);

    if (!g_mesh)
        fatalf("Unable to open mesh.");

    for (lod = 0; lod < 2; lod++)
    {
        Mesh mesh = subdivide(g_mesh);
        free_mesh(g_mesh);
        g_mesh = mesh;
    }

    finalize(g_mesh);
}

static void draw()
{
    static double theta = 15;
    theta++;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0, 0, -1);
    glRotated(theta, 0, 0, 1);
    glRotated(theta, 1, 0, 0);
    draw_facets(g_mesh, 1);
    glPopMatrix();
}

int main(int argc, char** argv)
{
    unsigned int drawDelay = (unsigned int) (1000.0f / maxFPS);
    unsigned int currentTime;
    unsigned int previousDrawTime;
    int done = 0;
    OS_Event event;

    osInit(512, 512, OS_OVERLAY, 0);
    osWaitVsync(1);
    init();

    currentTime = osGetMilliseconds();
    previousDrawTime = currentTime;

    while (!done)
    {
        while (osPollEvent(&event))
        {
            switch(event.type)
            {
                case OS_QUIT:
                    done = 1;
                    break;

                case OS_KEYUP:
                    switch (event.key.key)
                    {
                        case 'x': case 'X': case 'q': case 'Q':
                        case OSK_ESCAPE:
                            done = 1;
                            break;
                    }
            }
        }

        currentTime = osGetMilliseconds();
        if (currentTime - previousDrawTime > drawDelay)
        {
            draw();
            osSwapBuffers();
            previousDrawTime = currentTime;
        }
    }

    free_mesh(g_mesh);
    return 0;
}
