
#include "defs.h"
#include "thread.h"
#include "render.h"
#include "update.h"
void* thread_ctrl(
    INOUT void* pArg) 
{
    THREAD_t* pThread = (THREAD_t*)pArg;
    while (1) {
        pthread_mutex_lock(&pThread->mutex);
        while (!pThread->ready) 
        {
            pthread_cond_wait(&pThread->cond, &pThread->mutex);
        }
        pThread->ready = false;
        BOOL quit = pThread->quit;
        pthread_mutex_unlock(&pThread->mutex);

        if (quit)
        {
            break;
        }

        if (pThread->job == THREAD_JOB_UPDATE)
            update_do((UPDATE_DATA_t*)pThread->pData);
        else
            render_do((RENDER_DATA_t*)pThread->pData);

        pthread_mutex_lock(&pThread->mutex);
        pThread->done = true;
        pthread_cond_signal(&pThread->cond);
        pthread_mutex_unlock(&pThread->mutex);
    }
    return NULL;
}

void thread_markReady(
    OUT THREAD_t* pThread) 
{
    pthread_mutex_lock(&pThread->mutex);
    pThread->ready = true;
    pThread->done = false;
    pthread_cond_signal(&pThread->cond);
    pthread_mutex_unlock(&pThread->mutex);
}

void thread_waitTillDone(
    INOUT THREAD_t* pThread) 
{
    pthread_mutex_lock(&pThread->mutex);
    while (!pThread->done)
    {
        pthread_cond_wait(&pThread->cond, &pThread->mutex);
    } 
    pthread_mutex_unlock(&pThread->mutex);
}

void thread_markQuit(
    OUT THREAD_t* pThread) 
{
    pthread_mutex_lock(&pThread->mutex);
    pThread->quit = true;
    pThread->ready = true;
    pthread_cond_signal(&pThread->cond);
    pthread_mutex_unlock(&pThread->mutex);
}

void thread_swapBuffers(
    OUT UPDATE_DATA_t* pDataUpdate,
    OUT RENDER_DATA_t* pDataRender) 
{   
    FRAMEBUFFER_t* pTempFramebuffer = pDataUpdate->pFramebuffer;
    pDataUpdate->pFramebuffer = pDataRender->pFramebuffer;
    pDataRender->pFramebuffer = pTempFramebuffer;
}