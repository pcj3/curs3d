#include "defs.h"


#include "trans.h"
#include "triangle.h"
#include "raster.h"

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
    VECTOR4_t ptA0 = {-size/2, size, 0, 1};
    VECTOR4_t ptB0 = {-size, 0, 0, 1};
    VECTOR4_t ptC0 = {0, 0, 0, 1};

    VECTOR4_t ptA1 = {size/2, size, 0, 1};
    VECTOR4_t ptB1 = {size, 0, 0, 1};
    VECTOR4_t ptC1 = {0, 0, 0, 1};

    VECTOR4_t ptA2 = {-size, 0, 0, 1};
    VECTOR4_t ptB2 = {size, 0, 0, 1};
    VECTOR4_t ptC2 = {0, -size, 0, 1};

    VECTOR4_t ptAA;
    VECTOR4_t ptBA;
    VECTOR4_t ptCA;

    VECTOR4_t ptAB;
    VECTOR4_t ptBB;
    VECTOR4_t ptCB;

    VECTOR4_t ptAC;
    VECTOR4_t ptBC;
    VECTOR4_t ptCC;


    MATRIX44_t trans;
    MATRIX44_t transScaled;
    MATRIX44_t transRotated;

    VECTOR3_t vecScale = {1, 1, 1};
    VECTOR3_t vecRotate = {0, 1, 0};
    R4 angleRotate = 0.f * PI_R4 / 180.0f;
    R4 angleRotateStep = 0.01f;
    I ch;

    FRAMEBUFFER_t framebuffer;
    TRIANGLE_t triangleA;
    TRIANGLE_t triangleB;
    TRIANGLE_t triangleC;

    while (true)
    {   

        matrix44_setToIdentity(&trans);
        trans_scaleMatrix44ByVector3(&trans, &vecScale, &transScaled);
        trans_rotateMatrix44ByVector3(&transScaled, &vecRotate, 
                                    angleRotate, &transRotated);

        trans_multiplyMatrix44ByVector4(&transRotated, &ptA0, &ptAA);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptB0, &ptBA);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptC0, &ptCA);

        trans_multiplyMatrix44ByVector4(&transRotated, &ptA1, &ptAB);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptB1, &ptBB);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptC1, &ptCB);

        trans_multiplyMatrix44ByVector4(&transRotated, &ptA2, &ptAC);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptB2, &ptBC);
        trans_multiplyMatrix44ByVector4(&transRotated, &ptC2, &ptCC);

        triangleA.ptA = ptAA;
        triangleA.ptB = ptBA;
        triangleA.ptC = ptCA;
        
        triangleB.ptA = ptAB;
        triangleB.ptB = ptBB;
        triangleB.ptC = ptCB;

        triangleC.ptA = ptAC;
        triangleC.ptB = ptBC;
        triangleC.ptC = ptCC;

        framebuffer_clear(' ', &framebuffer);
        framebuffer_setSize(WINDOW_WIDTH, WINDOW_HEIGHT, &framebuffer);

        raster_triangle(&triangleA, &framebuffer);
        raster_triangle(&triangleB, &framebuffer);
        raster_triangle(&triangleC, &framebuffer);
        raster_draw(&framebuffer);

        ch = getch();
        if (ch == 'q') {
            break;
        }

        angleRotate += angleRotateStep;

        napms(10); // small delay to reduce CPU use
        refresh();
        erase();
    }

    endwin();

	return 0;
}