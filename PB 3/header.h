#ifndef P3_H
#define P3_H

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

void progressCallback(int index, int data_size);
void handleData(void (*progressCallback)(int index, int data_size), char* data, int data_size);

#endif /* P3_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex
 * ./ex
 */