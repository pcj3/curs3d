#ifndef AUX_H
#define AUX_H

#include "curses.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

#define IN
#define OUT
#define INOUT
#define FALLTHROUGH
#define UNUSED(x) (void)(x)

typedef signed int            I;      // equal to I44
typedef signed char           I1;     // signed 1 byte integer
typedef signed short          I2;     // signed 2 byte integer
typedef signed long           I4;     // signed 4 byte integer
typedef signed long long      I8;     // signed 8 byte integer

typedef unsigned int          U;      // equal to #U4
typedef unsigned char         U1;     // unsigned 1 byte integer
typedef unsigned short        U2;     // unsigned 2 byte integer
typedef unsigned long         U4;     // unsigned 4 byte integer
typedef unsigned long long    U8;     // unsigned 8 byte integer

typedef float                 R4;     // 4 byte floating point
typedef double                R8;     // 8 byte floating point
typedef char                  CH;     // ASCII character
typedef bool                  BOOL;

typedef U1  COLOR_t;
typedef U2  DEPTH_t;

//#define DEBUG

#define MIN(a, b)   ((a) > (b) ? (b) : (a))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

#define PAD(X) U1 __PADNAME(__LINE__)[X]
#define __PADNAME(x) __pad##x

#define WINDOW_WIDTH    ((U4) (COLS))
#define WINDOW_HEIGHT   ((U4) (LINES))

#define FPS_TARGET (60)

#define PI_R4 (3.141592653f)
#define DEG_TO_RAD(X) ((X) * PI_R4 / 180.0f)

#endif // AUX_H