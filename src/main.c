#include "defs.h"
#include "triangle.h"
#include "time.h"
#include "render.h"
#include "draw.h"
#include "thread.h"
#include "camera.h"

int main()
{
    // Init data
    initscr();
    raw();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    // Prepare test data
    R4 size = 1.f;
    TRIANGLE_t trianglePre = {
        .ptA = {-size, size, 0, 1},
        .ptB = {size, size, 0, 1},
        .ptC = {0, -size, 0, 1}
    };

    TRIANGLE_t triangleAfter;
    VECTOR3_t vecTrans = {0.f, 0.f, -2.f};
    VECTOR3_t vecScale = {1.f, 1.f, 1.f};
    VECTOR3_t vecRotate = {0.f, 1.f, 1.f};
    R4 angleRotate = 0.0;
    R4 angleRotateStep = DEG_TO_RAD(1);

    // Prepare camera
    CAMERA_t camera;
    camera.fieldOfView= 1.6f;
    camera.aspectRatio = ((R4) WINDOW_WIDTH / 2.f) / (R4) (WINDOW_HEIGHT);
    camera.planeFar = 400.f;;
    camera.planeNear = .2f;
    camera_setView(&camera);
    camera_setProjection(&camera);
    camera_setViewProjected(&camera);


    // Prepare thread data
    FRAMEBUFFER_t pFramebuffer[2];
    RENDER_DATA_t dataRender = {
        .pFramebuffer       = &pFramebuffer[0],
        .pMatViewProjected  = &camera.matViewProjected,
        .pTrianglePre       = &trianglePre,
        .pTriangleAfter     = &triangleAfter,
        .pVecTrans          = &vecTrans,
        .pVecScale          = &vecScale,
        .pVecRotate         = &vecRotate,
        .pAngleRotate       = &angleRotate
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


    MATRIX44_t A = { 1, 2, 3, 4, 5, 6, 7, 8, 9., 10, 11, 12, 13, 14, 15, 16};
    MATRIX44_t B = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("\nFIN\n");
    matrix44_print(&A);

    VECTOR3_t axis = {0, 1, 1};
    R4 angle = DEG_TO_RAD(45);
    printf("\nROT MAT\n");
    matrix44_rotateByVector3(&A, &axis, angle, &A);

    printf("\nROT RESULT\n");
    matrix44_print(&A);
	return 0;
}