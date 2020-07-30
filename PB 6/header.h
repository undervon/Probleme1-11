#ifndef P6_H
#define P6_H

#include<stdio.h>
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

Atom printHead(Queue* q);
Atom printTail(Queue* q);
void printQueue(Queue* q);

#endif /* P6_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex
 * ./ex
 */