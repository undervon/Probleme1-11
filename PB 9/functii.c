#include"header.h"

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread by synchronizing it with mutex.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{
    pthread_mutex_lock(&mutex);
    DBG_PRINT(5, "Thread: %d", (*(int*)thread)++);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}