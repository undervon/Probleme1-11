#include"headerQueue.h"

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 * \fn void initQueue(Queue* q)
 * \brief Function that initializes the queue.
 * \param[in] q Queue.
 * \return void
 **/
void initQueue(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

/**
 * \fn void push(Queue* q, Atom data) 
 * \brief Function that adds an integer value to the queue.
 * \param[in] q Queue.
 * \param[in] data The value that is put in the queue.
 * \return void
 **/
void push(Queue* q, Atom data)
{
    pthread_mutex_lock(&queue_mutex);
    Node* node = (Node*)malloc(sizeof(Node));
    if (NULL == node)
    {
        DBG_PRINT(1, "Error when allocating memory for the node!");
        exit(EXIT_FAILURE);
    }

    node->date = data;
    node->next = NULL;

    if (NULL == q->tail)
    {
        q->tail = node;
        q->head = node;
    }
    else
    {
        q->tail->next = node;
        q->tail = node;
    }
    pthread_mutex_unlock(&queue_mutex);
}

/**
 * \fn Atom pop(Queue* q)
 * \brief Function that extracts the head of the queue.
 * \param[in] q Queue.
 * \return Atom return_value The value in the head of the queue.
 **/
Atom pop(Queue* q)
{
    pthread_mutex_lock(&queue_mutex);
    if (true == isEmpty(q))
    {
        DBG_PRINT(1, "The queue is empty!");
        exit(EXIT_FAILURE);
    }

    Node* node = q->head;
    Atom return_value = node->date;

    q->head = q->head->next;
    if (true == isEmpty(q))
        q->head = NULL;

    if (NULL != node)
    {
        free(node);
        node = NULL;
    }
    return return_value;
    pthread_mutex_unlock(&queue_mutex);
}

/**
 * \fn bool isEmpty(Queue* q)
 * \brief Function that returns whether the queue is empty or not.
 * \param[in] q Queue.
 * \return bool True if the queue is empty / false otherwise.
 **/
bool isEmpty(Queue* q)
{
    if (NULL == q->head)
        return true;
    else
        return false;   
}   