#include"header.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    int pthread_error = 0;
    int sleep_error = 0;
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_THREADS);
    if (NULL == threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the threads!");
        exit(EXIT_FAILURE);
    }

    /* creating pthreads */
    DBG_PRINT(2, "Starting the threads:");
    stop_process = false;
    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_error = pthread_create(&threads[i], NULL, printThreads, (void*)(long)i);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }

    /* set sleep for 5 seconds */
    sleep_error = sleep(5);
    if (0 != sleep_error)
    {
        DBG_PRINT(1, "Error! Sleep was interrupted.");
        exit(EXIT_FAILURE);
    }

    /* signal for stopping the threads */
    pthread_mutex_lock(&mutex);

    stop_process = true;
    pthread_cond_broadcast(&condition);

    pthread_mutex_unlock(&mutex);

    /* waits for all threads */
    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_error = pthread_join(threads[i], NULL);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }
    DBG_PRINT(2, "The threads is done!");

    /* destroy the mutex and the condition */
    pthread_error = pthread_mutex_destroy(&mutex);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_destroy(&condition);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    /* memory deallocation */
    if (NULL != threads)
    {
        free(threads);
        threads = NULL;
    }

    return 0;
}