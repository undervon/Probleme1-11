#ifndef P11_H
#define P11_H

#include"headerQueue.h"

#define NUMBER_OF_PRODUCERS 10

typedef struct _ENGINE_DATA
{
    Queue* q;
    pthread_mutex_t mutex;
    pthread_cond_t producer;
    pthread_cond_t consumer;
    pthread_t consumer_thread;
    int is_ready;
}ENGINE_DATA;

void* initializeEngine(void);
int startEngine(void* engine);
int produce(void* engine, int index);
int onConsume(void* engine, int index);
void stopEngine(void* engine);
void destroyEngine(void* engine);

extern ENGINE_DATA engine_data;
extern int count;

#endif /* P11_H */