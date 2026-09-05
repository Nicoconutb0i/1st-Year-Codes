#include<stdio.h>

char *getdayName(int userInput){
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    if(userInput > 7 || userInput < 1){
        return "INVALID";
    }

    return days[userInput - 1];
}

int main(){
    int userInput;

    printf("Enter day: ");
    scanf("%d", &userInput);

    printf("Day of the week: %s", getdayName(userInput));

    return 0;
}