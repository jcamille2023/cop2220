/*
    Jossaya Camille
    April 5th, 2024
    A program that will take a word as an input and make a hash word.
*/
//add name, date and a brief description here
#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include <stdio.h>
#include <ctype.h> //for toupper and tolower
#include <string.h> //for strlen and strcat and strcpy
//STUDENT 1
//input character
//ask and get a word from the user
void JossayaGetInput(char inputWord[]);
//input 2 character arrays
//create an all uppercase version of the input word and store in the
// second parameter(upperWord);
void JossayaMakeUpper(char inputWord[], char upperWord[]);
//input 2 character arrays (one all uppercase)
//create a hashtag/ tilde version of the uppercase word and store in the
// second parameter(hashWord)
void JossayaHashtag(char upperWord[], char hashWord[]);
//input 3 character arrays
//concatenate all three together and store the result in the FIRST
//parameter (inputWord)
//add (upperWord) to (inputWord) then add (hashWord) to (inputWord) use
//strcat
void JossayaCompound(char inputWord [], char upperWord [], char hashWord []);

int main()
{
//declare 3 character arrays size 
char again, ar1[100], ar2[100],ar3[100], ar4[100];
do {
    int n;
    
    JossayaGetInput(ar1);
    strcpy(ar4,ar1);
    JossayaMakeUpper(ar1,ar2);
    JossayaHashtag(ar2,ar3);
    JossayaCompound(ar1,ar2,ar3);
    printf("The three words are: \n");
    printf("-----------\n\n");
    printf("input: ");
    for(n = 0;n<strlen(ar4);n++) {
        printf("%c",ar4[n]);
    }
    printf("\n");
    printf("lowercase: ");
    for(n = 0;n<strlen(ar2);n++) {
        printf("%c",ar2[n]);
    }
    printf("\n");
    printf("hash: ");
    for(n = 0;n<strlen(ar3);n++) {
        printf("%c",ar3[n]);
    }
    printf("\n");
    printf("All together: ");
    for(n = 0;n<strlen(ar1);n++) {
        printf("%c",ar1[n]);
    }
    printf("\n");
    printf("Would you like to enter another word? Y if yes, N if no.\n");
    scanf(" %c", &again);
} while (again == 'y' || again == 'Y');
printf("\nHave a great day!\n");
return 0;
}
//input character
//ask and get a word from the user
void JossayaGetInput(char inputWord[])
{
    int len;
    
    printf("Enter a word (exclude spaces):\n");
    scanf(" %s", inputWord);
    len = (int)strlen(inputWord);
    inputWord[len] = "\0";
    return;
}
//input 2 character arrays
//create an all uppercase version of the input word and store in the
// second parameter(upperWord)
void JossayaMakeUpper(char inputWord[], char upperWord[])
{
    int len, n;
    len = strlen(inputWord);
    for(n=0;n<len;n++) {
        upperWord[n] = toupper(inputWord[n]);
    }

    upperWord[len] = "\0";
}
//input 3 character arrays
//concatenate all three together and store the result in the FIRST
//parameter (inputWord)
//add (upperWord) to (inputWord) then add (hashWord) to (inputWord)
void JossayaHashtag(char upperWord[], char hashWord[])
{
//copy input word into lowerword (use strcpy)
//get the length
//search through and replace the characters in the hashtag word
    int i, length; // used in the loop
    char t; // t is a variable that stores the character
    length = strlen(upperWord);
    for(i = 0; i < length; i++) {
        if(upperWord[i] == 'A' || upperWord[i] == 'E' || upperWord[i] == 'I' || upperWord[i] == 'O' || upperWord[i] == 'U') {
            t = '#';
        }
        else {
            t = '~';
        }
        hashWord[i] = t;
        }
    hashWord[length] = "\0";
    return;
}
void JossayaCompound(char inputWord [], char upperWord [], char hashWord [])
{
    strcat(inputWord,hashWord);
    strcat(inputWord, upperWord);

    return;
}
//input 2 character arrays (one all uppercase)
//create a hashtag/ tilda version of the uppercase word and store in the
//second parameter(hashWord)

