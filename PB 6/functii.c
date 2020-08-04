#include"header.h"

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
}

/**
 * \fn Atom pop(Queue* q)
 * \brief Function that extracts the head of the queue.
 * \param[in] q Queue.
 * \return Atom return_value The value in the head of the queue.
 **/
Atom pop(Queue* q)
{
    if (true == isEmpty(q))
    {
        DBG_PRINT(1, "The queue is empty!");
        exit(EXIT_FAILURE);
    }

    Node* node = q->head;
    Atom return_value = node->date;

    q->head = q->head->next;
    if (true == isEmpty(q))
        q->tail = NULL;    

    if (0 != node)
    {
        free(node);
        node = NULL;
    }
    return return_value;
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

/**
 * \fn Atom printHead(Queue* q)
 * \brief Function that returns the head of the queue.
 * \param[in] q Queue.
 * \return Atom The head of the tail.
 **/
Atom printHead(Queue* q)
{
    if (true == isEmpty(q))
    {
        DBG_PRINT(1, "The queue is empty!");
        exit(EXIT_FAILURE);
    }
    return q->head->date;
}

/**
 * \fn Atom printTail(Queue* q)
 * \brief Function that returns the tail queue.
 * \param[in] q Queue.
 * \return Atom The tail of the tail.
 **/
Atom printTail(Queue* q)
{   
    if (true == isEmpty(q))
    {
        DBG_PRINT(1, "The queue is empty!");
        exit(EXIT_FAILURE);
    }
    return q->tail->date;
}

/**
 * \fn void printQueue(Queue* q)
 * \brief Function that displays the contents of the queue.
 * \param[in] q Queue.
 * \return void
 **/
void printQueue(Queue* q)
{
    if (true == isEmpty(q))
    {
        DBG_PRINT(1, "The queue is empty!");
        exit(EXIT_FAILURE);
    }
    while (0 != q->head)
    {
        printf("%d ", q->head->date);
        q->head = q->head->next;
    }
}