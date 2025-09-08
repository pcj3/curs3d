#include "defs.h"
#include "trans.h"
#include "triangle.h"
#include "raster.h"
#include "time.h"

int main()
{   

    // Init data
    initscr();
    raw();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE); // getch() won't block

    // Prepare test data
    R4 size = 0.6f;
    VECTOR4_t ptA = {-size/2, size, 0, 1};
    VECTOR4_t ptB = {-size, 0, 0, 1};
    VECTOR4_t ptC = {0, 0, 0, 1};

    MATRIX44_t trans;
    MATRIX44_t transScaled;
    MATRIX44_t transRotated;

    VECTOR3_t vecScale = {1, 1, 1};
    VECTOR3_t vecRotate = {0, 1, 0};
    R4 angleRotate = 0.01f * PI_R4 / 180.0f;
    angleRotate = 0.01f;
    I ch;

    FRAMEBUFFER_t framebuffer;
    TRIANGLE_t triangleA;
    matrix44_setToIdentity(&trans);
    trans_scaleMatrix44ByVector3(&trans, &vecScale, &transScaled);
    trans_rotateMatrix44ByVector3(&transScaled, &vecRotate, 
                                angleRotate, &transRotated);

    R8 timeLast = time_getTimeInSec();
    while (true)
    {   
        erase();

        if (time_capFps(timeLast))
        {
            continue;
        }
        timeLast = time_getTimeInSec();

        trans_multiplyMatrix44ByVector4(&transRotated, &ptA, &ptA);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptB, &ptB);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptC, &ptC);

        triangleA.ptA = ptA;
        triangleA.ptB = ptB;
        triangleA.ptC = ptC;

        framebuffer_clear(0, &framebuffer);

        framebuffer_setSize(WINDOW_WIDTH, WINDOW_HEIGHT, &framebuffer);

        raster_triangle(&triangleA, &framebuffer);
        raster_draw(&framebuffer);
        refresh();
        
        ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    endwin();

	return 0;
}