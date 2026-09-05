#include<stdio.h>

int max(int *arr, int size){
    
    int largest = arr[0];

    for(int i = 1; i < size; i++){
        if(largest < *(arr + i)){
            largest = *(arr + i);
        }
    }

    return largest;
}

int main(){

    int entryNum;
    int arr[100];

    do{
        printf("Enter number of entries: ");
        scanf("%d", &entryNum);

        if(entryNum <= 0){
            printf("Invalid: You must enter an integer greater than 0\n");
        }
    }while(entryNum <= 0);
    
    for(int i = 0; i < entryNum; i++){
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int largestNum = max(arr, entryNum);

    printf("Largest Number: %d", largestNum);

    return 0;
}