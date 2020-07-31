#include"header.h"

ENGINE_DATA engine_data;
int count = 0;

void* initializeEngine(void)
{
    int pthread_error = 0;

    engine_data.q = (Queue*)malloc(sizeof(Queue));
    if (NULL == engine_data.q)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data.q!");
        exit(EXIT_FAILURE);
    }
    initQueue(engine_data.q);

    pthread_error = pthread_mutex_init(&engine_data.mutex, NULL);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_init(&engine_data.producer, NULL);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_init(&engine_data.consumer, NULL);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    engine_data.consumer_thread = NULL;

    engine_data.is_ready = -1;

    pthread_exit(NULL);
}

int startEngine(void* engine)
{
    
    return 0;
}

int produce(void* engine, int index)
{
    pthread_mutex_lock(&engine_data.mutex);
    
    if (-1 == engine_data.is_ready)
        pthread_cond_wait(&engine_data.producer, &engine_data.mutex);
    while (0 != engine_data.is_ready)
        pthread_cond_wait(&engine_data.producer, &engine_data.mutex);
    /**/

    DBG_PRINT(5, "Producer -> ID Thread:%ld, index:%d ", (long)engine, index);
    push(engine_data.q, index);

    /**/
    pthread_cond_signal(&engine_data.consumer);
    pthread_mutex_unlock(&engine_data.mutex);
    return 0;
}

int onConsume(void* engine, int index)
{   
    pthread_mutex_lock(&engine_data.mutex);

    while (count < NUMBER_OF_PRODUCERS)
    {
        if (-1 == engine_data.is_ready)
        {
            engine_data.is_ready = 0;
            pthread_cond_signal(&engine_data.producer);
        }
        while (0 == engine_data.is_ready)
            pthread_cond_wait(&engine_data.consumer, &engine_data.mutex);
        /**/

        DBG_PRINT(5, "Consumer -> ID Thread:%ld, index:%d, pop value:%d ", 
        (long)engine, index, pop(engine_data.q));

        /**/
        engine_data.is_ready = 0;
        ++count;
        pthread_cond_signal(&engine_data.producer);
    }
    pthread_mutex_unlock(&engine_data.mutex);
    return 0;
}

void stopEngine(void* engine)
{
    
}

void destroyEngine(void* engine)
{
    int pthread_error = 0;

    if (NULL != engine_data.q)
    {
        free(engine_data.q);
        engine_data.q = NULL;
    }

    pthread_error = pthread_mutex_destroy(&engine_data.mutex);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_destroy(&engine_data.producer);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_destroy(&engine_data.consumer);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    engine_data.is_ready = -1;
}