#ifndef P5_H
#define P5_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include"../p4h.h"

typedef struct _COMPONENT_DATA
{
    int attributes;
    char* name;
    size_t name_size;
}COMPONENT_DATA, *PCOMPONENT_DATA;

int serializeData(COMPONENT_DATA* component_info, void* buffer, size_t buffer_size, size_t* result);
int deserializeData(void* buffer, size_t buffer_size, COMPONENT_DATA* component_info, size_t* result);

#endif /* P5_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex
 * ./ex
 */