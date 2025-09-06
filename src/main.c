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

    // Prepare test data
    VECTOR4_t ptA0 = {10, 10, 0, 1};
    VECTOR4_t ptB0 = {20, 10, 0, 1};
    VECTOR4_t ptC0 = {15, 20, 0, 1};

    VECTOR4_t ptA;
    VECTOR4_t ptB;
    VECTOR4_t ptC;
    MATRIX44_t trans;
    MATRIX44_t transScaled;
    MATRIX44_t transRotated;

    VECTOR3_t vecScale = {2, 1, 1};
    
    matrix44_setToIdentity(&trans);
    trans_scaleMatrix44ByVector3(&trans, &vecScale, &transScaled);

    trans_multiplyMatrix44ByVector4(&transScaled, &ptA0, &ptA);
    trans_multiplyMatrix44ByVector4(&transScaled, &ptB0, &ptB);
    trans_multiplyMatrix44ByVector4(&transScaled, &ptC0, &ptC);

    TRIANGLE_t triangle = {ptA, ptB, ptC};
    FRAMEBUFFER_t framebuffer = {WINDOW_WIDTH, WINDOW_HEIGHT};

    draw_raster(&triangle, &framebuffer);

    wgetch(stdscr);
    wclear(stdscr);


    endwin();

	return 0;
}