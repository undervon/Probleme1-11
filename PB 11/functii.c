#include"header.h"

ENGINE_DATA* engine_data;
/* pthread_cond_t condition = PTHREAD_COND_INITIALIZER; */
pthread_cond_t condition;
bool is_ready = false;

bool* consumer_thread_created;
bool* producer_thread_created;

/**
 * \fn void* initializeEngine(void)
 * \brief Allocates an internal ENGINE_DATA* struct.
 * \param void
 * \return void*
 **/
void* initializeEngine(void)
{
    int pthread_error = 0;

    engine_data->q = (Queue*)malloc(sizeof(Queue));
    if (NULL == engine_data->q)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data.q!");
        exit(EXIT_FAILURE);
    }
    initQueue(engine_data->q);

    engine_data->consumer_thread = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_CONSUMER);
    if (NULL == engine_data->consumer_thread)
    {
        DBG_PRINT(1, "Error when allocating memory for the engine_data.consumer_thread!");
        exit(EXIT_FAILURE);
    }

    pthread_error = pthread_cond_init(&condition, NULL);
    if (0 != pthread_error) 
    {
        DBG_PRINT(1, "Error! Code for pthread_cond_init: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    consumer_thread_created = (bool*)malloc(sizeof(bool) * NUMBER_OF_CONSUMER);
    if (NULL == consumer_thread_created)
    {
        DBG_PRINT(1, "Error when allocating memory for the consumer_thread_created!");
        exit(EXIT_FAILURE);
    }

    return NULL;
}

/**
 * \fn int startEngine(void* engine)
 * \brief Starts the consumer thread that consumes the queue.
 * \param[in] engine ENGINE_DATA* struct.
 * \return int 
 **/
int startEngine(void* engine)
{
    int pthread_error = 0;
    int i = 0;
    for (i = 0; i < NUMBER_OF_CONSUMER; i++)
    {
        pthread_error = pthread_create(&engine_data->consumer_thread[i], NULL, (void*)onConsume, (void*)(long)i);
        if (0 != pthread_error)
        {
            consumer_thread_created[i] = false;
            DBG_PRINT(1, "Error! Code for pthread_create: %d", pthread_error);
            exit(EXIT_FAILURE);
        }
        else
            consumer_thread_created[i] = true;
    }
    
    return 0;
}

/**
 * \fn int produce(void* engine, int index)
 * \brief A function that receives an integer, prints it's thread id and index value and calls push into the synchronized queue, engine must be previously created with initializeEngine.
 * \param[in] engine ENGINE_DATA* struct. 
 * \param[in] index Index.
 * \return int 
 **/
int produce(void* engine, int index)
{
    int rand_value = rand();
    printf ("In producer thread...\n");
    sleep (1);
    
    DBG_PRINT(5, "Producer -> ID Thread:%ld, index:%d ", (long)engine, index);
    push(engine_data->q, rand_value);
    while (false != is_ready)
        pthread_cond_wait (&condition, &queue_mutex);

    is_ready = true;
    pthread_cond_signal (&condition);
    return 0;
}

/**
 * \fn int onConsume(void* engine, int index)
 * \brief A function that is called by a consumer thread and extracts elements and prints them.
 * \param[in] engine ENGINE_DATA* struct. 
 * \param[in] index Index.
 * \return int 
 **/
int onConsume(void* engine, int index)
{   
    printf ("In consumer thread...\n");
    while (false == is_ready)
        pthread_cond_wait (&condition, &queue_mutex);

    DBG_PRINT(5, "Consumer -> ID Thread:%ld, index:%d, pop value:%d ", 
    (long)engine, index, pop(engine_data->q));

    is_ready = false;
    pthread_cond_signal (&condition);
    return 0;
}

/**
 * \fn void stopEngine(void* engine)
 * \brief Signals and waits the consumer thread to finish.
 * \param[in] engine ENGINE_DATA* struct.
 * \return void 
 **/
void stopEngine(void* engine)
{
    int pthread_error = 0;
    int i = 0;
    for (i = 0; i < NUMBER_OF_CONSUMER; i++)
    {
        if (true == consumer_thread_created[i])
        {
            pthread_error = pthread_join(engine_data->consumer_thread[i], NULL);
            if (0 != pthread_error)
            {
                DBG_PRINT(1, "Error! Code for pthread_join: %d", pthread_error);
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
 * \fn void destroyEngine(void* engine)
 * \brief Deallocates ENGINE_DATA* members created with initializeEngine and struct.
 * \param[in] engine ENGINE_DATA* struct.
 * \return void 
 **/
void destroyEngine(void* engine)
{
    if (NULL != engine_data->q)
    {
        free(engine_data->q);
        engine_data->q = NULL;
    }

    if (NULL != engine_data->consumer_thread)
    {
        free(engine_data->consumer_thread);
        engine_data->consumer_thread = NULL;
    }

    if (NULL != consumer_thread_created)
    {
        free (consumer_thread_created);
        consumer_thread_created = NULL;
    }
}