#ifndef P4_H
#define P4_H

#include<stdio.h>

#define DBG_PRINT(debug_level, format, ...) fprintf(stderr, "[%d] [%s] [%d] "format" \n", debug_level, __FILE__, __LINE__, ##__VA_ARGS__)

#endif /* P4_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c
 * gcc -Wall main.o -o ex
 * ./ex
 */