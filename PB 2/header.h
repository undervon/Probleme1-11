#ifndef P2_H
#define P2_H

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

uint32_t getValue(char* buffer, int offset, int buffer_size);

#endif /* P2_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.o -o ex
 * ./ex
 */