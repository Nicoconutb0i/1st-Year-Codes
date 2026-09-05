#ifndef STATISTICS_H
#define STATISTICS_H

#define TRUE 1
#define FALSE 0

typedef struct node *nodePtr;

struct node{
	float item;
	nodePtr next;
};

typedef nodePtr Statistician, DataStore;

Statistician newStatistician();
void destroyStatistician(Statistician s);
void add(Statistician s, float x);
void REMOVE(Statistician s, float x);
int isEmpty(Statistician s);
void showData(Statistician s);

void displayData(Statistician s);
float minimum(Statistician s);
float maximum(Statistician s);
void range(float max, float min);
float mean(Statistician s);
void median(Statistician s);
void mode(Statistician s);
float variance(Statistician s, float ave);
void standardDeviation(float var);

#endif