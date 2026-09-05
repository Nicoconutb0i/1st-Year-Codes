#include<stdio.h>
#include<string.h>
#include<ctype.h>

int vowelCounter(char arr[]);
int consonantCounter(char arr[]);

int main(){

    char string[100];

    printf("Enter a string: ");
    scanf("%[^\n]", string);

    int vowels = vowelCounter(string);
    int consonants = consonantCounter(string);

    printf("Number of vowels: %d", vowels);
    printf("\nNumber of consonants: %d", consonants);

    return 0;
}

int vowelCounter(char arr[]){

    int vowelCount = 0;

    for(int i = 0; i < strlen(arr); i++){

        char c = arr[i];
        c = tolower(c);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowelCount++;
        }
    }

    return vowelCount;
}

int consonantCounter(char arr[]){

    int consonantCount = 0;

    for(int i = 0; i < strlen(arr); i++){

        char c = arr[i];
        c = tolower(c);

        if(isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            consonantCount++;
        }
    }

    return consonantCount;
}

