#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct list{
    int count;
    NODE *head;
    NODE *tail;
}LIST;

void insertFront(LIST *, int);
void insertRear(LIST *, int);
void insertAt(LIST *, int, int);
void deleteFront(LIST *);
void deleteRear(LIST *);
void deleteAt(LIST *, int);
void displayAll(LIST *);

#endif // HEADER_H_INCLUDED