#include<stdio.h>

int findSmallest(int arr[], int size);
int findLargest(int arr[], int size);

int main(){

    int array[10];

    for(int i = 0; i < 10; i++){
        printf("Enter a number[%d]: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Your output:");

    for(int i = 0; i < 10; i++){
        printf(" %d", array[i]);
    }

    int smallestNum = findSmallest(array, 10);
    int largestNum = findLargest(array, 10);

    printf("\nSmallest number: %d", smallestNum);
    printf("\nLargest number: %d", largestNum);

    return 0;
}

int findSmallest(int arr[], int size){

    int min = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}

int findLargest(int arr[], int size){

    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}
