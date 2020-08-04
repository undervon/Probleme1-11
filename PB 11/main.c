#include"header.h"

int main(int argc, char const *argv[])
{   
    int pthread_error = 0;
    int i = 0;

    engine_data = (ENGINE_DATA*)malloc(sizeof(ENGINE_DATA));
    if (NULL ==  engine_data)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data!");
        exit(EXIT_FAILURE);
    }

    initializeEngine();
    startEngine(&engine_data);
    
    pthread_t* producer_threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_PRODUCERS);
    if (NULL == producer_threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the producer_threads!");
        exit(EXIT_FAILURE);
    }

    producer_thread_created = (bool*)malloc(sizeof(bool) * NUMBER_OF_PRODUCERS);
    if (NULL == producer_thread_created)
    {
        DBG_PRINT(1, "Error when allocating memory for the producer_thread_created!");
        exit(EXIT_FAILURE);
    }    

    for (i = 0; i < NUMBER_OF_PRODUCERS; i++)
    {
        pthread_error = pthread_create(&producer_threads[i], NULL, (void*)produce, (void*)(long)i);
        if (0 != pthread_error)
        {
            producer_thread_created[i] = false;
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
        else
            producer_thread_created[i] = true;
    }
    
    for (i = 0; i < NUMBER_OF_PRODUCERS; i++)
    {
        if (true == producer_thread_created[i])
        {
            pthread_error = pthread_join(producer_threads[i], NULL);
            if (0 != pthread_error)
            {
                DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
                exit(EXIT_FAILURE);
            }
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

    pthread_error = pthread_cond_destroy(&condition);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    /* memory deallocation */
    if (NULL != producer_threads)
    {
        free(producer_threads);
        producer_threads = NULL;
    }

    if (NULL != producer_thread_created)
    {
        free(producer_thread_created);
        producer_thread_created = NULL;
    }

    if (NULL != engine_data)
    {
        free(engine_data);
        engine_data = NULL;
    }

    pthread_exit(NULL);

    return 0;
}
