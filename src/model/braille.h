#ifndef MODEL_BRAILLE_h
#define MODEL_BRAILLE_h

#include "defs.h"



#define BRAILLE_UNICODE_OFFSET  (0x2800)
#define BRAILLE_DOTS_COUNT      (8)
#define BRAILLE_OFFSET_LEFT     (.166f)
#define BRAILLE_OFFSET_RIGHT    (.166f)
#define BRAILLE_OFFSET_ROW0     (.3f)
#define BRAILLE_OFFSET_ROW1     (.1f)
#define BRAILLE_OFFSET_ROW2     (.1f)
#define BRAILLE_OFFSET_ROW3     (.3f)

typedef struct BRAILLE_LUT_s {
    R4 dx;
    R4 dy;
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
    return ((dotMask >> dotIdx) & 1);
}

static inline void braille_setDot(U1* pDotMask , U1 dotIdx)
{
    (*pDotMask |= (1u << dotIdx));
}


#endif // MODEL_BRAILLE_h