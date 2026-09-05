#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}NODE;

typedef struct list{
    int count;
    struct node *head;
    struct node *tail;
}LIST;

void insertFront(LIST*, int);
void insertRear(LIST*, int);
void insertAt(LIST*, int, int);
void removeFront(LIST*);
void removeRear(LIST*);
void removeAt(LIST*, int);
void printList(LIST*);
void printMirror(LIST*);

#endif