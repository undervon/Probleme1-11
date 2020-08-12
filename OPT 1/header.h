#ifndef O1_H
#define O1_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../p4h.h"

#define MAX_LINE 128

typedef struct _Node
{
    char* word;
    int freq;
    struct _Node* next;
}Node;

bool isEmpty(Node* node);
void insert_node(Node** node, char* value);
void print_node(Node* node);
void sort_node(Node** node);

#endif /* O1_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.c -o ex
 * ./ex
 */