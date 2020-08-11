#ifndef O2_H
#define O2_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include"../p4h.h"

#define DIM_BUFFER 1024
#define DIM_MAX_STRING_ARRAY 1024

char* open_file(void);
FILE* save_file(char* file_name, char* complete_file_name);
void print_file_content(char* complete_file_name);
void write_text_at_position(char string_array[DIM_MAX_STRING_ARRAY][DIM_MAX_STRING_ARRAY], FILE* fptr);
void delete_text_from_position(char string_array[DIM_MAX_STRING_ARRAY][DIM_MAX_STRING_ARRAY], FILE* fptr);

#endif /* O2_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.c -o ex
 * ./ex
 */