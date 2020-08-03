#include"header.h"

ENGINE_DATA engine_data;

void* initializeEngine(void)
{
    engine_data.q = (Queue*)malloc(sizeof(Queue));
    if (NULL == engine_data.q)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data.q!");
        exit(EXIT_FAILURE);
    }
    initQueue(engine_data.q);

    engine_data.consumer_thread = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_CONSUMER);
    if (NULL == engine_data.consumer_thread)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data.consumer_thread!");
        exit(EXIT_FAILURE);
    }
    return NULL;
}

int startEngine(void* engine)
{
    int pthread_error = 0;
    for (int i = 0; i < NUMBER_OF_CONSUMER; i++)
    {
        pthread_error = pthread_create(&engine_data.consumer_thread[i], NULL, (void*)onConsume, (void*)(long)i);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}

int produce(void* engine, int index)
{
    int rand_value = rand();
    DBG_PRINT(5, "Producer -> ID Thread:%ld, index:%d ", (long)engine, index);
    push(engine_data.q, rand_value);
    return 0;
}

int onConsume(void* engine, int index)
{   
    DBG_PRINT(5, "Consumer -> ID Thread:%ld, index:%d, pop value:%d ", 
    (long)engine, index, pop(engine_data.q));
    return 0;
}

void stopEngine(void* engine)
{
    int pthread_error = 0;
    for (int i = 0; i < NUMBER_OF_CONSUMER; i++)
    {
        pthread_error = pthread_join(engine_data.consumer_thread[i], NULL);
        if (0 != pthread_error)
        {
            DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
    }
}

void destroyEngine(void* engine)
{
    if (NULL != engine_data.q)
    {
        free(engine_data.q);
        engine_data.q = NULL;
    }

    if (NULL != engine_data.consumer_thread)
    {
        free(engine_data.consumer_thread);
        engine_data.consumer_thread = NULL;
    }
}