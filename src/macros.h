#ifndef AUX_H
#define AUX_H

#define IN
#define OUT     //!< 
#define INOUT   //!< read and write parameter

typedef signed int            I;      //!< equal to  
typedef signed char           I1;     //!< signed 1 byte integer
typedef signed short          I2;     //!< signed 2 byte integer
typedef signed long           I4;     //!< signed 4 byte integer
typedef signed long long      I8;     //!< signed 8 byte integer

typedef unsigned int          U;      //!< equal to #U4 
typedef unsigned char         U1;     //!< unsigned 1 byte integer
typedef unsigned short        U2;     //!< unsigned 2 byte integer
typedef unsigned long         U4;     //!< unsigned 4 byte integer
typedef unsigned long long    U8;     //!< unsigned 8 byte integer

typedef float                 R4;     //!< 4 byte floating point
typedef double                R8;     //!< 8 byte floating point
typedef char                  CH;     //!< ASCII character
#endif // AUX_H