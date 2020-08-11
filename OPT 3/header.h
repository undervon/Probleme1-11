#ifndef O3_H
#define O3_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include"../p4h.h"

#define MAX_TEXT 256    /* maximum message size */

typedef struct _msg_buffer
{
    long msg_type;
    char msg_text[MAX_TEXT];
}msg_buffer;

void sent_message(msg_buffer buffer, key_t key);
void recovery_message(msg_buffer buffer, key_t key);

#endif /* O3_H */

/* 
 * Commands for the compiling on the command line.
 * gcc -c -Wall main.c functii.c
 * gcc -Wall main.o functii.c -o ex
 * ./ex
 */