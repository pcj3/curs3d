#include "defs.h"
#include "triangle.h"
#include "time.h"
#include "render.h"
#include "draw.h"
#include "thread.h"

int main()
{   
    // Init data
    initscr();
    raw();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    // Prepare test data
    R4 size = 0.5f;
    TRIANGLE_t trianglePre = {
        .ptA = {-size, size, 0, 1},
        .ptB = {size, size, 0, 1},
        .ptC = {0, -size, 0, 1}
    };
    TRIANGLE_t triangleAfter;
    MATRIX44_t trans;
    VECTOR3_t vecScale = {1, 1, 1};
    VECTOR3_t vecRotate = {0, 1, 0};
    R4 angleRotate = 0.0;
    R4 angleRotateStep = 1.f * PI_R4 / 180.0f;

    // Prepare thread data
    FRAMEBUFFER_t pFramebuffer[2];
    RENDER_DATA_t dataRender = {
        .pFramebuffer   = &pFramebuffer[0],
        .pTrianglePre   = &trianglePre,
        .pTriangleAfter = &triangleAfter,
        .pMatTrans      = &trans,
        .pVecScale      = &vecScale,
        .pVecRotate     = &vecRotate,
        .pAngleRotate   = &angleRotate
    };

    DRAW_DATA_t dataDraw = {
        .pFramebuffer   = &pFramebuffer[1]
    };

    // Prepare threads
    pthread_t threadRenderId;
    THREAD_t threadRender = {
        .mutex  = PTHREAD_MUTEX_INITIALIZER,
        .cond   = PTHREAD_COND_INITIALIZER,
        .job    = THREAD_JOB_RENDER,
        .pData  = &dataRender,
        .ready  = false,
        .done   = false,
        .quit   = false,
    };

    pthread_t threadDrawId;
    THREAD_t threadDraw = {
        .mutex  = PTHREAD_MUTEX_INITIALIZER,
        .cond   = PTHREAD_COND_INITIALIZER,
        .job    = THREAD_JOB_DRAW,
        .pData  = &dataDraw,
        .ready  = false,
        .done   = false,
        .quit   = false,
    };

    // Prepare loop control data
    I pressedKey;
    R8 timeLast = time_getTimeInSec();

    // Start threads
    pthread_create(&threadRenderId, NULL, thread_ctrl, &threadRender);
    pthread_create(&threadDrawId, NULL, thread_ctrl, &threadDraw);

    // Start main loop
    while (1)
    {     
        // Wait for frame on time grid
        time_waitForFrame(&timeLast);

        // Signal threads
        thread_markReady(&threadRender);
        thread_markReady(&threadDraw);

        // Wait till completed
        thread_waitTillDone(&threadRender);
        thread_waitTillDone(&threadDraw);

        // Swap buffers
        thread_swapBuffers(&dataRender, &dataDraw);
        
        // Do some stuff (to be moved to update)
        angleRotate += angleRotateStep;
 
        // Exit when requested
        pressedKey = getch();
        if (pressedKey == 'q') {
            break;
        }    
    }
    // Exit threads
    thread_markQuit(&threadRender);
    thread_markQuit(&threadDraw);
    pthread_join(threadRenderId, NULL);
    pthread_join(threadDrawId, NULL);

    // Close stdscr
    endwin();
	return 0;
}