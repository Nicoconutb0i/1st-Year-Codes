#include"header.h"

void insertRear(LIST *l, int data){
    NODE *newNode = malloc(sizeof(NODE));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = l->tail;

    if(l->tail == NULL){
        l->head = newNode;
        l->tail = newNode;
    }
    else{
        l->tail->next = newNode;
        l->tail = newNode;
    }

    l->count++;
}