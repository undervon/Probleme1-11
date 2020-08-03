#ifndef P10_H
#define P10_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#include"../p4h.h"

#define NUMBER_OF_THREADS 10
#define COUNT_NUMBER 100

void* printThreads(void* thread);

extern pthread_barrier_t barrier;
extern bool stop_process;
extern time_t local_time;
extern int count;

#endif /* P10_H */

/**
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex -lpthread
 * ./ex
*/