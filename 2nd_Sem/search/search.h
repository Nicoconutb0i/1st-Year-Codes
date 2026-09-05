#ifndef SEARCH_H
#define SEARCH_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int index;
	int data;
	struct node *n, *p; 
}NODE;

typedef struct list{
	int count;
	struct node *head;
	struct node *tail;
}LIST;

typedef NODE* point; 

bool binarySearch(LIST *list_ptr, int key, int location[], int *j);
bool linearSearch(LIST *list_ptr,int key,int location[],int *j);
void insertRear(int x, LIST *list_ptr,int index);
void qSort(LIST *list_ptr,NODE *start, NODE *end);
point partition(LIST *L,NODE *start, NODE *end);
void generate(LIST *list_ptr);
void destroy(LIST *list_ptr);
void printSort(LIST *L);
void menu();

#endif
