#ifndef P10V2_H
#define P10V2_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#include"../p4h.h"

#define NUMBER_OF_THREADS 10

void* printThreads(void* thread);

extern bool stop_process;
extern pthread_mutex_t mutex;
extern pthread_cond_t condition;

#endif /* P10_H */

/**
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex -lpthread
 * ./ex
*/