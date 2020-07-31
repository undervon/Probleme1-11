#include"header.h"

int main(int argc, char const *argv[])
{   
    int pthread_error = 0;
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * NUMBER_OF_PRODUCERS);
    if (NULL == threads)
    {
        DBG_PRINT(1, "Error when allocating memory for the threads!");
        exit(EXIT_FAILURE);
    }

    initializeEngine();

    

    pthread_error = pthread_mutex_destroy(&queue_mutex);
    if (0 != pthread_error)
    {
        DBG_PRINT(1, "Error! Code for pthread_mutex_destroy: %d", pthread_error);
        exit(EXIT_FAILURE);
    }

    destroyEngine(&engine_data);

    if (NULL != threads)
    {
        free(threads);
        threads = NULL;
    }

    pthread_exit(NULL);

    return 0;
}
