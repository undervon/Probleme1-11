#include"header.h"

pthread_barrier_t barrier;

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread and stops with a stop condition.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{
    int sleep_error = 0;
    int pthread_error = 0;
    pthread_error = pthread_barrier_wait(&barrier);
    if (0 != pthread_error)
        DBG_PRINT(1, "Error! Code for pthread_barrier_wait: %d", pthread_error);

    while (false == stop_process)
    {
        sleep_error =  sleep(1);
        if (0 != sleep_error)
            DBG_PRINT(1, "Error! Sleep was interrupted.");
        DBG_PRINT(5, "Time:%d, Thread: %d", (int)time(NULL), (*(int*)thread)++);
    }
    pthread_exit(NULL);
}