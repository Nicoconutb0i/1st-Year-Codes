#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#define MAXSIZE 100

typedef struct node {
    char data;
    struct node* link;
} NODE;

typedef struct {
    NODE* front;
    NODE* rear;
    int count;
} QUEUE;

QUEUE* createQueue(void);

bool enqueue(QUEUE* queue, char dataIn);
bool dequeue(QUEUE* queue, char* dataOut);

bool isEmpty(QUEUE* queue);
bool isFull(QUEUE* queue);

#endif
