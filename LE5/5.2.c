#include<stdio.h>

int main(){

    int userInput, passcode = 1234;

    for(int i = 0; i < 3; i++){
        printf("What is the passcode: ");
        scanf("%d", &userInput);

        if(userInput == passcode){
            printf("ACCESS GRANTED\n");
            return 0;
        }
    }

    printf("ACCESS DENIED\n");

    return 0;
}
