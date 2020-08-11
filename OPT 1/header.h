#ifndef O1_H
#define O1_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../p4h.h"

#define NUMBER_OF_WORD 6

typedef struct _Node
{
    char* word;
    int freq;
    struct _Node* next;
}Node;

bool isEmpty(Node* node);
void insert(Node** node, char* value);
void print(Node* node);
void sort(Node** node);

#endif /* O1_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.c -o ex
 * ./ex
 */