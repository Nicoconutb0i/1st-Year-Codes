#include<stdio.h>

int extractFirstLSD(int num);
int extractSecondLSD(int num);
int sumDigits(int x, int y);

int main(){

    int input, result, firstNum, secondNum;

    printf("Enter a number: ");
    scanf("%d", &input);

    firstNum = extractFirstLSD(input);
    secondNum = extractSecondLSD(input);

    result = sumDigits(firstNum, secondNum);

    printf("Sum: %d + %d = %d", secondNum, firstNum, result);

    return 0;
}

int extractFirstLSD(int num){
    return num % 10;
}

int extractSecondLSD(int num){
    return (num / 10) % 10;
}

int sumDigits(int x, int y){
    return x + y;
}
