#ifndef P8_H
#define P9_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include"../p4h.h"

#define NUMBER_OF_THREADS 10

void* printThreads(void* thread);

#endif /* P8_H */

/**
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex -lpthread
 * ./ex
*/