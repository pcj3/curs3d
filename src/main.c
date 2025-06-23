#include <curses.h>
#include "matrix33.h"
#include "matrix44.h"
#include "vector3.h"
#include "trans.h"
#include "macros.h"
#include <stdio.h>

int main()
{
	VECTOR3_t vecA = {1.f, 2.f, 3.f};
	MATRIX44_t matA = {2.f, 4.f, 6.f, 8.f,\
						16.f, 32.f, 64.f, 128.f,\
						256.f, 512.f, 1024.f, 2048.f};
	MATRIX44_t matB;
	trans_rotateMatrix44ByVector3(&matA, &vecA, &matB);

	return 0;
}