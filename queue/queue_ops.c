#include <stdlib.h>
#include "header.h"


QUEUE* createQueue(void) {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    }
    return queue;
}

bool enqueue(QUEUE* queue, char dataIn) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode) return false;

    newNode->data = dataIn;
    newNode->link = NULL;

    if (queue->count == 0) {
        queue->front = newNode;
    } else {
        queue->rear->link = newNode;
    }

    queue->rear = newNode;
    queue->count++;
    return true;
}

bool dequeue(QUEUE* queue, char* dataOut) {
    if (queue->count == 0) return false;

    NODE* temp = queue->front;
    *dataOut = temp->data;

    queue->front = queue->front->link;

    if (queue->count == 1) {
        queue->rear = NULL;
    }

    free(temp);
    queue->count--;
    return true;
}

bool isEmpty(QUEUE* queue) {
    return (queue->count == 0);
}
