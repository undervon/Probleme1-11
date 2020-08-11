#include"header.h"

bool stop_process = true;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread and stops with a stop condition.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{
    pthread_mutex_lock(&mutex);

    long argument = (long)thread;
    while (false == stop_process)
    {
        DBG_PRINT(5, "The thread id: %ld works", argument);
        pthread_cond_wait(&condition, &mutex);
    }

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}