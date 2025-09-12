#include "braille.h"
#include "defs.h"

/*
    Braille dot indices:

    Row 0:  d0  d3
    Row 1:  d1  d4
    Row 2:  d2  d5
    Row 3:  d6  d7

*/
const BRAILLE_LUT_t BRAILLE_LUT[BRAILLE_DOTS_COUNT] = {
    {-BRAILLE_OFFSET_LEFT,    -BRAILLE_OFFSET_ROW0},
    {-BRAILLE_OFFSET_LEFT,    -BRAILLE_OFFSET_ROW1},
    {-BRAILLE_OFFSET_LEFT,    +BRAILLE_OFFSET_ROW2},
    {+BRAILLE_OFFSET_RIGHT,   -BRAILLE_OFFSET_ROW0},
    {+BRAILLE_OFFSET_RIGHT,   -BRAILLE_OFFSET_ROW1},
    {+BRAILLE_OFFSET_RIGHT,   +BRAILLE_OFFSET_ROW2},
    {-BRAILLE_OFFSET_LEFT,    +BRAILLE_OFFSET_ROW3},
    {+BRAILLE_OFFSET_RIGHT,   +BRAILLE_OFFSET_ROW3},
};

U1 braille_countDots(
    U1 dotMask)
{
    dotMask = dotMask - ((dotMask >> 1) & 0x55);
    dotMask = (dotMask & 0x33) + ((dotMask >> 2) & 0x33);
    return (((dotMask + (dotMask >> 4)) & 0x0F) * 0x01);
}
