#ifndef P7_H
#define P7_H

#include<stdio.h>
#include<stdlib.h>
#include"../p4h.h"

extern int* allocInLib(void);
extern void freeInLib(int* object);

#endif /* P7_H */

/**
 * Compilation links
 * https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
 * 
 * Commands for the compiling on the command line.
 * gcc -c -Wall -Werror -fpic functii.c
 * gcc -shared -o libsample.so functii.o
 * gcc -o ex main.c -L. -lsample
 * echo $LD_LIBRARY_PATH
 * export LD_LIBRARY_PATH=.
 * echo $LD_LIBRARY_PATH
 * ./ex
 **/