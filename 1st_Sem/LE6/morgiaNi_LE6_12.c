#include<stdio.h>
#include<stdbool.h>

bool isLetter(char ch);
bool isVowel(char ch);

int main(){

    char letter;

    printf("Enter a letter: ");
    scanf("%c", &letter);

    if(isLetter(letter) == true){
        if(isVowel(letter) == true){
            printf("VOWEL");
        } else {
            printf("CONSONANT");
        }
    } else {
        printf("INVALID INPUT!");
    }

    return 0;
}

bool isLetter(char ch){
    if((ch >='a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return true;
    } else {
        return false;
    }
}

bool isVowel(char ch){
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    } else {
        return false;
    }
}
