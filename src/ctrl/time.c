#include <unistd.h>
#include <sys/time.h>

#include "defs.h"
#include "time.h"

R8 time_getTimeInSec() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (R8) (tv.tv_sec + tv.tv_usec * US_TO_S);
}

void time_waitForFrame(IN R8* pTimeLast)
{
    R8 timeCurrent = time_getTimeInSec();
    R8 timeDelta = timeCurrent - *pTimeLast;
    if (timeDelta < FRAME_TIME)
    {
        useconds_t timeSleep = (useconds_t)((FRAME_TIME - timeDelta) * S_TO_US);
#ifdef DEBUG
        R8 start = time_getTimeInSec();
#endif // DEBUG
        usleep(timeSleep);
#ifdef DEBUG
        R8 end = time_getTimeInSec();
        useconds_t timeRealSleep = (useconds_t)((end - start) * S_TO_US);
        printf("FPS: %.3f REQ: %.3fms, SLEPT: %.3fms, DIFF: %.3fms\n",
        (R8) (1.0 / (end - *pTimeLast)),
        (R8) (timeSleep * US_TO_MS),
        (R8) (timeRealSleep * US_TO_MS),
        (R8) ((timeRealSleep - timeSleep) * US_TO_MS));
#endif // DEBUG
    }
     *pTimeLast = time_getTimeInSec();
 }