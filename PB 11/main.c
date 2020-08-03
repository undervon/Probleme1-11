#include"header.h"

int main(int argc, char const *argv[])
{   
    int pthread_error = 0;

    initializeEngine();
    startEngine(&engine_data);
    
    pthread_t* producer_threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_PRODUCERS);
    if (NULL == producer_threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the producer_threads!");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUMBER_OF_PRODUCERS; i++)
    {
        pthread_error = pthread_create(&producer_threads[i], NULL, (void*)produce, (void*)(long)i);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < NUMBER_OF_PRODUCERS; i++)
    {
        pthread_error = pthread_join(producer_threads[i], NULL);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }

    stopEngine(&engine_data);
    destroyEngine(&engine_data);

    pthread_error = pthread_mutex_destroy(&queue_mutex);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    if (NULL != producer_threads)
    {
        free(producer_threads);
        producer_threads = NULL;
    }

    pthread_exit(NULL);

    return 0;
}
