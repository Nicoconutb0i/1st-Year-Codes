#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include "Statistics.h"

Statistician newStatistician(){
	nodePtr NEW = (struct node*)malloc(sizeof(struct node));
	NEW->next = NULL;
	return NEW;
}

void destroyStatistician(Statistician s){
	Statistician ForDeletion = (struct node*)malloc(sizeof(struct node));
	ForDeletion = s->next;
	s->next = NULL;
	free(ForDeletion);
	while(s->next)
	return;
}

void add(Statistician s, float x){
	nodePtr NEW = (struct node*)malloc(sizeof(struct node));
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	
	if(s->next == NULL){
		NEW->item = x;
		NEW->next = NULL;
		s->next = NEW;
	} else {
		TEMP = s;
		while(TEMP->next != NULL){
			TEMP = TEMP->next;
		}
		NEW->item = x;
		NEW->next = NULL;
		TEMP->next = NEW;
	}
	
	return;
}


void REMOVE(Statistician s, float x){
	nodePtr ForDeletion = (struct node*)malloc(sizeof(struct node));
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	int tempCount=0, i=0;
	
	if(s->next->item == x && s->next->next == NULL){
		free(s->next);
		s->next = NULL;
		printf("Deleted last number in the statistician!");
		printf("\nSTATISTICIAN DATA  : EMPTY");
		printf("\n\nPress any key to continue.");
		return;
	} else {
		ForDeletion = s->next;
		if(ForDeletion->item == x){
			s->next = ForDeletion->next;
			ForDeletion = NULL;
			free(ForDeletion);
			printf("Successfully deleted data!");
			return;
		} 
		
		while(ForDeletion->item != x && ForDeletion->next != NULL){
			ForDeletion = ForDeletion->next;
			tempCount= tempCount +1;

			if(ForDeletion->item == x){
				TEMP = s->next;

				for(i = 1; i < tempCount; i++){
					TEMP = TEMP->next;
				}

				if(ForDeletion->next != NULL){
					TEMP->next = ForDeletion->next;
				} else {
					TEMP->next = NULL;
				}

				printf("Successfully deleted data in Statistician!");
				showData(s->next);
				free(ForDeletion);
				return;
			}
		} 
	}

	ForDeletion->next = NULL;
	ForDeletion = NULL;
	free(ForDeletion);
	printf("Data could not be found in statistician! Press any key to continue.");
	return;	
}


int isEmpty(Statistician s){
	if(s->next == NULL){
		return TRUE;
	} else {
		return FALSE;
	}
}

void displayData(Statistician s){
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	TEMP = s;
	float min, max, average, VARIANCE, SD;
	
	system("cls");
	printf("[ Display Statistics ]\n\n");
	printf("STATISTICIAN DATA  : ");
	
	while(s != NULL){
		printf("%.2f   ",s->item );
		s = s->next;
	}
	
	min = minimum(TEMP);
	max = maximum(TEMP);
	range(max, min);
	average = mean(TEMP);
	median(TEMP);
	mode(TEMP);
	VARIANCE = variance(TEMP, average);
	standardDeviation(VARIANCE);

	printf("\n\nPress any key to continue...");
	return;
}


float minimum(Statistician s){
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	float MIN = s->item;

	if(s->next != NULL){
		TEMP = s->next;
		if(TEMP->item < MIN){
			MIN = TEMP->item;
		}
		while(TEMP->next != NULL){
			TEMP = TEMP->next;
			if(TEMP->item < MIN){
				MIN = TEMP->item;
			}
		}
	}

	TEMP = NULL;
	free(TEMP);
	printf("\nMinimum            : %.2f", MIN);
	return MIN;
}

float maximum(Statistician s){
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	float MAX = s->item;
	if(s->next != NULL){
		TEMP = s->next;

		if(TEMP->item > MAX){
			MAX = TEMP->item;
		}

		while(TEMP->next != NULL){
			TEMP = TEMP->next;

			if(TEMP->item > MAX){
				MAX = TEMP->item;
			}
		}
	}

	TEMP = NULL;
	free(TEMP);
	printf("\nMaximum            : %.2f", MAX);
	return MAX;
}

void range(float max, float min){
	printf("\nRange              : %.2f", max-min);
	return;
}

float mean(Statistician s){
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	float sum = s->item, MEAN = s->item;
	int count=1;
	
	if(s->next != NULL){
		TEMP = s;
		while (TEMP->next != NULL){
			TEMP = TEMP->next;
			count = count +1;
			sum = sum + TEMP->item;
		}

		MEAN = sum / ((float)count);
	}

	printf("\nMean(Average)      : %.2f", MEAN);
	return MEAN;
}

void median(Statistician s){
	float tempArray[50], temp;
	float MEDIAN;
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	TEMP = s;
	int count = 1, i, j;
	
	while(TEMP->next != NULL){
		count = count +1; TEMP = TEMP->next;
	}
	
	TEMP = s;
	for(i=0; i<count; i++){
		tempArray[i] = TEMP->item; TEMP = TEMP->next;
	}
	
	for(i=0; i<count; i++){
	 	for(j=0; j<count-1;j++){
	 		if(tempArray[j]>tempArray[j+1]){
	 			temp = tempArray[j];
	 			tempArray[j] = tempArray[j+1];
	 			tempArray[j+1] = temp;
			}
		}
	}

	if(count%2 == 0){
		MEDIAN = (tempArray[(count-1)/2]+ tempArray[count/2])/2.0;
	} else {
		MEDIAN = tempArray[count/2];
	}

	printf("\nMedian             : %.2f", MEDIAN);
	
	TEMP = NULL;
	free(TEMP);

	return;
}

void mode(Statistician s){
	float tempMode[50], tempLIST[50];
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	TEMP = s;

	int count=1, i, j, k = 0, n = 1, MODE, MAX = 0;
	
	while(TEMP->next != NULL){
		count = count +1; TEMP = TEMP->next;
	}

	TEMP = s;
	for(i=0; i<count; i++){
		tempMode[i] = TEMP->item; TEMP = TEMP->next;
	}
	
    for(i = 0; i < count - 1; i++){
        MODE = 0;

        for(j = i + 1; j < count; j++){
            if(tempMode[i] == tempMode[j]){
                MODE++;
            }
        }
        
		if((MODE > MAX) && (MODE != 0)){
            k = 0;
            MAX = MODE;
            tempLIST[k] = tempMode[i];
            k++;
        } else if(MODE == MAX){
            tempLIST[k] = tempMode[i];
            k++;
        }
    }
    
	for(i = 0; i < count; i++){
        if(tempMode[i] == tempLIST[i]) n++;
    }
        if(n == count){
			printf("\nMode               : All values appeared just once");
            return;
		} else {
            printf("\nMode               : ");
            for (i = 0; i < k; i++) printf("%.2f, ",tempLIST[i]);
        }
		printf("the number/s appeared %d times", n);

	TEMP = NULL;
	return;		
}

float variance(Statistician s, float ave){	
	nodePtr TEMP = (struct node*)malloc(sizeof(struct node));
	float sum = (s->item - ave)*(s->item - ave);
	float VARIANCE = (float)0;
	int count=1;
	
	if(s->next != NULL){
		TEMP = s;
		while(TEMP->next != NULL){
			TEMP = TEMP->next;
			count = count +1;
			sum = sum + ((TEMP->item - ave)* (TEMP->item - ave));
		}
		VARIANCE = sum / ((float)count);
		printf("\nVariance           : %.5f", VARIANCE);
		return VARIANCE;
	} else {
		printf("\nVariance           : NULL");
	}
	
	TEMP = NULL;
	free(TEMP);
	return 0.0;
}

void standardDeviation(float var){
	if(var != 0.0){
		printf("\nStandard Deviation : %f", sqrt(var));
	} else {
		printf("\nStandard Deviation : NULL");
	}
}

void showData(Statistician s){
	printf("\nSTATISTICIAN DATA  : ");
	while(s != NULL){
		printf("%.2f   ",s->item );
		s = s->next;
	}
	printf("\n\nPress any key to continue.");
	return;
}
