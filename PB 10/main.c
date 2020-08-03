#include"header.h"

bool stop_process = true;
time_t local_time;

int main(int argc, char const *argv[])
{   
    int pthread_error = 0;
    int sleep_error = 0;
    int* increment_value = NULL;
    bool* thread_create = NULL;

    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_THREADS);
    if (NULL == threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the threads!");
        exit(EXIT_FAILURE);
    }

    increment_value = (int*)malloc(sizeof(int));
    if (NULL == increment_value)
    {
        DBG_PRINT(1, "Error when allocating memory for the increment_value!");
        exit(EXIT_FAILURE);
    }

    thread_create = (bool*)malloc(sizeof(bool) * NUMBER_OF_THREADS);
    if (NULL == thread_create)
    {
        DBG_PRINT(1, "Error when allocating memory for the thread_create!");
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_barrier_init(&barrier, NULL, NUMBER_OF_THREADS);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_barrier_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }
    
    stop_process = false;
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {      
        pthread_error = pthread_create(&threads[i], NULL, printThreads, (void*)increment_value);
        if (0 != pthread_error) 
        {
            thread_create[i] = false;
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
        else
            thread_create[i] = true;
    }

    sleep_error = sleep(5);
    if (0 != sleep_error)
    {
        DBG_PRINT(1, "Error! Sleep was interrupted.");
        exit(EXIT_FAILURE);
    }

	stop_process = true;

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
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

    pthread_error = pthread_barrier_destroy(&barrier);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_barrier_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
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

    if (NULL != increment_value)
    {
        free(increment_value);
        increment_value = NULL;
    }

    pthread_exit(NULL);

    return 0;
}
