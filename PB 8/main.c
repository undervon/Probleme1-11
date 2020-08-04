#include"header.h"

int main(int argc, char const *argv[])
{
    int pthread_error = 0;
    bool* thread_create = NULL;
    int i = 0;

    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_THREADS);
    if (NULL == threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the threads!");
        exit(EXIT_FAILURE);
    }

    thread_create = (bool*)malloc(sizeof(bool) * NUMBER_OF_THREADS);
    if (NULL == thread_create)
    {
        DBG_PRINT(1, "Error when allocating memory for the thread_create!");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        /* creating threads */
        pthread_error = pthread_create(&threads[i], NULL, printThreads, (void*)(long)i);
        if (0 != pthread_error)
        {
            thread_create[i] = false;
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
        else
            thread_create[i] = true;
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        /* threads are expected */
        if (true == thread_create[i])
        {
            pthread_error = pthread_join(threads[i], NULL);
            if (0 != pthread_error)
            {
                DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
                exit(EXIT_FAILURE);
            }
        }
    }
    
    /* memory deallocation */
    if (NULL != threads)
    {
        free(threads);
        threads = NULL;
    }

    if (NULL != thread_create)
    {
        free(thread_create);
        thread_create = NULL;
    }

    pthread_exit(NULL);

    return 0;
}