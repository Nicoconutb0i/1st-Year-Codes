#ifndef LIST_H
#define LIST_H

typedef struct node{
	int i;
	int x;
	struct node *n;
	struct node *p;
}NODE;

typedef struct list{
	struct node *head;
	struct node *tail;
	int count;
}LIST;

void createList(LIST *L, int x);
void destroyList(LIST *L);
void insertEnd(LIST *L, int data);
void deleteEnd(LIST *L);
void displayList(NODE *head);

#endif
