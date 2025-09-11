#ifndef CTRL_TIME_h
#define CTRL_TIME_h

#include "defs.h"

#define FRAME_TIME (1.0 / FPS_TARGET)
#define S_TO_US 1e6
#define US_TO_S 1e-6
#define US_TO_MS 1e-3

R8 time_getTimeInSec();

void time_waitForFrame(
    IN R8* pTimeLast);

#endif // CTRL_TIME_h