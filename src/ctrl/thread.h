#ifndef CTRL_THREAD_h
#define CTRL_THREAD_h

#include <pthread.h>
#include "defs.h"
#include "render.h"
#include "draw.h"

// Thread types
typedef enum THREAD_JOB_e { 
    THREAD_JOB_RENDER,
    THREAD_JOB_DRAW 
    } THREAD_JOB_t;

// Thread wrapper

typedef struct THREAD_s {
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    THREAD_JOB_t    job;
    void*           pData; // either 
    BOOL            ready;
    BOOL            done;
    BOOL            quit;
} THREAD_t;

void* thread_ctrl(
    INOUT void* pArg); 

void thread_markReady(
    OUT THREAD_t* pThread);

void thread_waitTillDone(
    INOUT THREAD_t* pThread);

void thread_markQuit(
    OUT THREAD_t* pThread);

void thread_swapBuffers(
    OUT RENDER_DATA_t* pDataRender,
    OUT DRAW_DATA_t* pDataDraw);


#endif // CTRL_THREAD_h