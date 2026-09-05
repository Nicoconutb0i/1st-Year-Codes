#include<stdio.h>

int main(){

    float firstMark, secondMark, thirdMark, fourthMark, average;

    printf("1st Mark: ");
    scanf("%f", &firstMark);

    if(firstMark < 0 || firstMark > 100){
        printf("INVALID INPUT!");
        return 1;
    }

    printf("2nd Mark: ");
    scanf("%f", &secondMark);

    if(secondMark < 0 || secondMark> 100){
        printf("INVALID INPUT!");
        return 1;
    }

    printf("3rd Mark: ");
    scanf("%f", &thirdMark);

    if(thirdMark < 0 || thirdMark > 100){
        printf("INVALID INPUT!");
        return 1;
    }

    printf("4th Mark: ");
    scanf("%f", &fourthMark);

    if(fourthMark < 0 || fourthMark > 100){
        printf("INVALID INPUT!");
        return 1;
    }

    average = (firstMark + secondMark + thirdMark + fourthMark) / 4.0 ;

    printf("FINAL GRADE: %.2f", average);
    if(average >= 50){
        printf("\nREMARKS: PASSED");
    } else {
        printf("\nREMARKS: FAILED");
    }

    return 0;
}
