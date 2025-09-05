#ifndef AUX_H
#define AUX_H

#define IN
#define OUT
#define INOUT

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

#define MIN(a, b)   ((a) > (b) ? (b) : (a))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

#define PAD(X) U1 __PADNAME(__LINE__)[X]
#define __PADNAME(x) __pad##x
#endif // AUX_H