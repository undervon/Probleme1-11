#include"header.h"

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread by synchronizing it with mutex and stops with a stop condition.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{
    int pthread_error = 0;
    pthread_mutex_lock(&mutex);
    while (false == stop_process)
        DBG_PRINT(5, "Thread: %d", (*(int*)thread)++);
    pthread_error = pthread_barrier_wait(&barrier);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_barrier_wait: %d", pthread_error);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}