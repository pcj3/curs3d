#include "defs.h"
#include "triangle.h"
#include "render.h"
#include "draw.h"
#include "thread.h"
#include "camera.h"
#include "obj.h"
#include "fps.h"

int main()
{
#ifdef MAC
    setlocale(LC_ALL, "en_US.UTF-8");
#else // MAC
    setlocale(LC_ALL, "");
#endif //MAC
    // Init data
    initscr();
    raw();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
    WINDOW* pWindow;
#ifdef DEBUG
    pWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
#else // DEBUG
    pWindow = stdscr;
#endif // DEBUG
    
    if (has_colors() && can_change_color() && COLORS >= SHADE_COUNT) 
    {
        for (U1 i = 1; i < SHADE_COUNT+1; i++) {
            U4 intensity = i * (U4)(1000 / SHADE_COUNT);
            init_color(100+i, 0, intensity, 0);
            init_pair(i, 100+i, COLOR_BLACK);
        }
    }

    // Prepare test data
    MODEL_t model;
    obj_read_model("res/cow.obj", &model);
    VECTOR3_t vecTrans = {0.f, 0.f, -10.f};
    VECTOR3_t vecScale = {1.f, 1.f, 1.f};
    VECTOR3_t vecRotate = {.0f, 1.0f, 0.f};
    R4 angleRotate = 0.0;
#ifdef DEBUG
    R4 angleRotateStep = DEG_TO_RAD(0);
#else //DEBUG
    R4 angleRotateStep = DEG_TO_RAD(1);
#endif // DEBUG

    // Prepare camera
    CAMERA_t camera;
    camera.vecPosition  = (VECTOR3_t){0, 0, 0};
    camera.vecRotation  = (VECTOR3_t){0, 0, 0};
    camera.vecLight     = (VECTOR3_t){0, 0, -5};
    camera.fieldOfView  = 1.2f;
    camera.aspectRatio  = ((R4) WINDOW_WIDTH / 2.f) / (R4) (WINDOW_HEIGHT);
    camera.planeFar     = 400.f;
    camera.planeNear    = .2f;
    camera_setView(&camera);
    camera_setProjection(&camera);
    camera_setViewProjected(&camera);


    // Prepare thread data
    FRAMEBUFFER_t pFramebuffer[2];
    RENDER_DATA_t dataRender = {
        .pFramebuffer       = &pFramebuffer[0],
        .pCamera            = &camera,
        .pModel             = &model,
        .pVecTrans          = &vecTrans,
        .pVecScale          = &vecScale,
        .pVecRotate         = &vecRotate,
        .pAngleRotate       = &angleRotate
    };

    DRAW_DATA_t dataDraw = {
        .pFramebuffer   = &pFramebuffer[1],
        .pWindow        = pWindow
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

    // Close windows
    delwin(pWindow);
    endwin();
	return 0;
}