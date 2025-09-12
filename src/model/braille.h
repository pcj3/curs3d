#ifndef MODEL_BRAILLE_h
#define MODEL_BRAILLE_h

#include "defs.h"

/*
    Using braille charachters.
    The dots are indexed as:

    d0 d4 (row 0)
    d1 e5 (row 1)
    d2 d6 (row 2)
    d3 e7 (row 3)

*/

#define BRAILLE_UNICODE_OFFSET  (0x2800)
#define BRAILLE_DOTS_COUNT      (8)
#define BRAILLE_OFFSET_LEFT     (.166f)
#define BRAILLE_OFFSET_RIGHT    (.166f)
#define BRAILLE_OFFSET_ROW0     (.168f)
#define BRAILLE_OFFSET_ROW1     (.002f)
#define BRAILLE_OFFSET_ROW2     (.164f)
#define BRAILLE_OFFSET_ROW3     (.330f)

typedef struct BRAILLE_LUT_s {
    R4 dx;
    R4 dy;
    U1 pos;
} BRAILLE_LUT_t;

extern const BRAILLE_LUT_t BRAILLE_LUT[];

typedef struct BRAILLE_S {
    U1 dotMask;
    DEPTH_t depths[BRAILLE_DOTS_COUNT];
} BRAILLE_t;

U1 braille_countDots(
    U1 dotMask);

static inline  U1 braille_getDotState(
    U1 dotMask,
    U1 dotIdx)
{
    return (dotMask >> dotIdx) & 1;
}

static inline void braille_setDot(U1* pDotMask , U1 dotIdx)
{
    *pDotMask |= (1u << dotIdx);
}


#endif // MODEL_BRAILLE_h