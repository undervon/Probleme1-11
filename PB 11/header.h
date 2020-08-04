#ifndef P11_H
#define P11_H

#include"headerQueue.h"

#define NUMBER_OF_PRODUCERS 10
#define NUMBER_OF_CONSUMER 1

typedef struct _ENGINE_DATA
{
    Queue* q;
    pthread_t* consumer_thread;
}ENGINE_DATA;

void* initializeEngine(void);
int startEngine(void* engine);
int produce(void* engine, int index);
int onConsume(void* engine, int index);
void stopEngine(void* engine);
void destroyEngine(void* engine);

extern ENGINE_DATA* engine_data;
extern pthread_cond_t condition;
extern bool is_ready;
extern bool* consumer_thread_created;
extern bool* producer_thread_created;

#endif /* P11_H */