#include"header.h"

int main(int argc, char const *argv[])
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (NULL == q)
    {
        DBG_PRINT(1, "Error when allocating memory for the q!");
        exit(EXIT_FAILURE);
    }

    initQueue(q);

    push(q, 1);
    push(q, 2);
    push(q, 9);

    /* printQueue(q); */

    printf("Head: %d\n", printHead(q));
    printf("Tail: %d\n", printTail(q));

    printf("%d\n", pop(q));
    printf("%d\n", pop(q));
    printf("%d\n", pop(q));
    printf("%d\n", pop(q));

    /* memory deallocation */
    if(NULL != q)
    {
        free(q);
        q = NULL;
    }

    return 0;
}