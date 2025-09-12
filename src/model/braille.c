#include "braille.h"
#include "defs.h"

const BRAILLE_LUT_t BRAILLE_LUT[BRAILLE_DOTS_COUNT] = {
    {-BRAILLE_OFFSET_LEFT,    -BRAILLE_OFFSET_ROW0, 0},
    {-BRAILLE_OFFSET_LEFT,    -BRAILLE_OFFSET_ROW1, 1},
    {-BRAILLE_OFFSET_LEFT,    +BRAILLE_OFFSET_ROW2, 2},
    {-BRAILLE_OFFSET_LEFT,    +BRAILLE_OFFSET_ROW3, 6},
    {+BRAILLE_OFFSET_RIGHT,   -BRAILLE_OFFSET_ROW0, 3},
    {+BRAILLE_OFFSET_RIGHT,   -BRAILLE_OFFSET_ROW1, 4},
    {+BRAILLE_OFFSET_RIGHT,   +BRAILLE_OFFSET_ROW2, 5},
    {+BRAILLE_OFFSET_RIGHT,   +BRAILLE_OFFSET_ROW3, 7},
};

U1 braille_countDots(
    U1 dotMask)
{
    dotMask = dotMask - ((dotMask >> 1) & 0x55);
    dotMask = (dotMask & 0x33) + ((dotMask >> 2) & 0x33);
    return (((dotMask + (dotMask >> 4)) & 0x0F) * 0x01);
}
