#include"header.h"

int count = 0;
pthread_barrier_t barrier;

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread and stops with a stop condition.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{
    local_time = time(NULL);
    int pthread_error = 0;
    pthread_error = pthread_barrier_wait(&barrier);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_barrier_wait: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    while (false == stop_process)
    {
        for (int i = 0; i < COUNT_NUMBER; ++i)
            count = count + i;
        DBG_PRINT(5, "Count:%d, time:%s", count, asctime(localtime(&local_time)));
        DBG_PRINT(5, "Thread: %d", (*(int*)thread)++);
    }
    pthread_exit(NULL);
}