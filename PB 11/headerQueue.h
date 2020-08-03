#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../p4h.h"

#define Atom int

typedef struct _Node
{
    Atom date;
    struct _Node* next;
}Node;

typedef struct _Queue
{
    Node* head;
    Node* tail;
}Queue;

void initQueue(Queue* q);

void push(Queue* q, Atom data);
Atom pop(Queue* q);

bool isEmpty(Queue* q);

extern pthread_mutex_t queue_mutex;

#endif /* QUEUE_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c functiiQueue.c
 * gcc -Wall main.o functii.o functiiQueue.o -o ex -lpthread
 * ./ex
 */