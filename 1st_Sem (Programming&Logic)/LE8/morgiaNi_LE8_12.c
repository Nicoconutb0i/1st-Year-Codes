#include<stdio.h>

int search(int *arr, int size, int key){

    for(int i = 0; i < size; i++){
        if(*(arr + i) == key){
            return i;
        }
    }
    
    return 1;
}

int main(){

    int userEntry, searchData;
    int arr[100];

    do{
        printf("Enter number of entries: ");
        scanf("%d", &userEntry);

        if(userEntry <= 0){
            printf("Invalid: You must enter an integer greater than 0!\n");
        }
    }while(userEntry <= 0);

    for(int i = 0; i < userEntry; i++){
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    printf("Search data: ");
    scanf("%d", &searchData);

    int index = search(arr, userEntry, searchData);

    if (index == 1){
        printf("NOT FOUND\n");
    } else {
        printf("FOUND at index %d\n", index);
    }

    return 0;
}