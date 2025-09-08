
#include <time.h>
#include <sys/time.h>

#include <unistd.h>

#include "defs.h"

R8 time_getTimeInSec() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

BOOL time_capFps(IN R8 timeLast)
{    
    R8 timeCurrent = time_getTimeInSec();
    R8 timeDelta = timeCurrent - timeLast;
    mvprintw(0, 0, "%f", 1. / timeDelta);
    if (timeDelta < MIN_FRAME_TIME) 
    {
        useconds_t sleep_us = (useconds_t)((MIN_FRAME_TIME - timeDelta) * 1e6);
        usleep(sleep_us);
        return true; // wait until next frame
    }
    return false;
}