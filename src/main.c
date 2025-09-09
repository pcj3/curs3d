#include "defs.h"
#include "trans.h"
#include "triangle.h"
#include "time.h"
#include "render.h"
#include "update.h"
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
    UPDATE_DATA_t dataUpdate = {
        .pFramebuffer   = &pFramebuffer[0],
        .pTrianglePre   = &trianglePre,
        .pTriangleAfter = &triangleAfter,
        .pMatTrans      = &trans,
        .pVecScale      = &vecScale,
        .pVecRotate     = &vecRotate,
        .pAngleRotate   = &angleRotate
    };

    RENDER_DATA_t dataRender = {
        .pFramebuffer   = &pFramebuffer[1]
    };

    // Prepare threads
    pthread_t threadUpdateId;
    THREAD_t threadUpdate = {
        .mutex  = PTHREAD_MUTEX_INITIALIZER,
        .cond   = PTHREAD_COND_INITIALIZER,
        .job    = THREAD_JOB_UPDATE,
        .pData  = &dataUpdate,
        .ready  = false,
        .done   = false,
        .quit   = false,
    };

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

    // Prepare loop control data
    I pressedKey;
    R8 timeLast = time_getTimeInSec();

    // Start threads
    pthread_create(&threadUpdateId, NULL, thread_ctrl, &threadUpdate);
    pthread_create(&threadRenderId, NULL, thread_ctrl, &threadRender);

    // Start main loop
    while (1)
    {     
        // Wait for frame on time grid
        time_waitForFrame(&timeLast);

        // Signal threads
        thread_markReady(&threadUpdate);
        thread_markReady(&threadRender);

        // Wait till completed
        thread_waitTillDone(&threadUpdate);
        thread_waitTillDone(&threadRender);

        // Swap buffers
        thread_swapBuffers(&dataUpdate, &dataRender);
        
        // Do some stuff (to be moved to update)
        angleRotate += angleRotateStep;
 
        // Exit when requested
        pressedKey = getch();
        if (pressedKey == 'q') {
            break;
        }    
    }
    // Exit threads
    thread_markQuit(&threadUpdate);
    thread_markQuit(&threadRender);
    pthread_join(threadUpdateId, NULL);
    pthread_join(threadRenderId, NULL);

    // Close stdscr
    endwin();
	return 0;
}