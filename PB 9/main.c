#include"header.h"

/* pthread_mutex_t mutex = PTHREAD_COND_INITIALIZER; */
pthread_mutex_t mutex;

int main(int argc, char const *argv[])
{
    int pthread_error = 0;
    int* value = NULL;
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

    pthread_error = pthread_mutex_init(&mutex, NULL);
    if (0 != pthread_error) 
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    value = (int*)malloc(sizeof(int));
    if (NULL == value)
    {
        DBG_PRINT(1, "Error when allocating memory for the value!");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_error = pthread_create(&threads[i], NULL, printThreads, (void*)value);
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

    pthread_error = pthread_mutex_destroy(&mutex);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    /* memory deallocation */
    if (NULL != threads)
    {
        free(threads);
        threads = NULL;
    }

    if (NULL != value)
    {
        free(value);
        value = NULL;
    }

    if (NULL != thread_create)
    {
        free(thread_create);
        thread_create = NULL;
    }

    pthread_exit(NULL);

    return 0;
}