#include<stdio.h>
#include<string.h>

void findLongestString(char longest[], int n){

    char temp[100];

    for(int i = 0; i < n; i++){
        printf("Enter string[%d]: ", i + 1);
        scanf(" %[^\n]", temp);

        if(strlen(temp) > strlen(longest)){
            strcpy(longest, temp);
        }
    }
}

int main(){

    char longest[100] = "";

    findLongestString(longest, 5);

    printf("\nThe longest string is: %s\n", longest);

    return 0;
}