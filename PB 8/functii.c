#include"header.h"

/**
 * \fn void* printThreads(void* thread)
 * \brief Displays the current thread.
 * \param[in] void* thread Thread.
 * \return void* Returns a thread.
 **/
void* printThreads(void* thread)
{   
    DBG_PRINT(5, "Thread: %ld", (long)thread);

    pthread_exit(NULL);
}