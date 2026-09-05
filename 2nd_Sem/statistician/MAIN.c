#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "Statistics.h"

void showMenu(int *choice);
int getNum(int *num);

int main(){
	int choice, statCount = 0, valid, running = TRUE;
	float num;
	
	struct node *first, *last;
	first = (struct node*)malloc(sizeof(struct node));
	last = first;
	
	DataStore Active = (Statistician)malloc(sizeof(struct node));
	Active->next = NULL;
	
	do{
		system("cls");
		choice = 0;
		valid = FALSE;
		showMenu(&choice);
		
		switch(choice){
		case 1:
			if(Active->next != NULL){
				printf("There already exists a Statistician datastore! Press any key to continue.");
				getch();
			} else {
				Active->next = newStatistician();
				printf("\nNew Statistician successfully created!");
				getch();
			}
			break;
		case 2:
			if(Active->next == NULL){
				printf("There is no existing Statistician datastore to delete! Press any key to continue.");
				getch();
			} else {
				destroyStatistician(Active);
				printf("\nCurrent Statistician successfully destroyed!"); 
				getch();
			}
			break;
		case 3:
			if(Active->next != NULL){
				printf("Number: ");

				if(!scanf("%f", &num)){
					printf("Invalid number. Press any key to continue");
				} else {
					add(Active->next, num);
					printf("\nData successfully added!");
					showData(Active->next->next);
				}
			} else {
				printf("There is no current Statistician datastore!");
			}
			getch();
			break;
		case 4:
			if(Active->next != NULL){
				if(isEmpty(Active->next) == TRUE){
					printf("There are no data in the statistician.");
				} else {					
					printf("Number: ");
					if(!scanf("%f", &num)){
						printf("Invalid number. Press any key to continue");
					} else {
						REMOVE(Active->next, num);
					}
				}
			} else {
				printf("There is no current Statistician datastore!");
			}
			getch();
			break;
		case 5:
			if(Active->next == NULL){
				printf("\nThere is currently no statistician datastore! Press any key to continue.");
			} else {
				if(isEmpty(Active->next) == TRUE){
					printf("There is currently no data in the statistician.");
				} else {
					displayData(Active->next->next);}
			}
			getch();
			break;
		case 6:
			return 0;
			break;
		default:
			getchar();
			break;
		}
		
	}while(running==1);
	
	getchar();
	return 0;
}


void showMenu(int *choice){
	system("cls");
	
	printf("[ Statistician ]\n");
	printf("\n  [1] New Statistician");
	printf("\n  [2] Destroy Statistician");
	printf("\n  [3] Add Data");
	printf("\n  [4] Delete Data");
	printf("\n  [5] Display Statistics");
	printf("\n  [6] QUIT");
	
	printf("\n\nChoice: ");
	scanf("%d", choice);
	
	return;
}

int getNum(int *x){
	if(!scanf("%d", x)){
		printf("\nInvalid number. Press any key to continue.\n");
		getch();
		return FALSE;
	} else {
		return TRUE;
	}
}
