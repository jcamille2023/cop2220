/* 
    Jossaya Camille
    Apr 23, 2024
    This are the notes for the final exam.
*/


#include <stdio.h> // includes printf, scanf statements
#include <string.h> // includes string functions, strcpy, strlen
#include <ctype.h> // includes toupper, tolower functions  

typedef struct {
    char name[50];
    int age;
    double favoriteNumber;
}person;

int main() {
    int age, num; // variables must be declared before use, types are int, char, double
    char name[50]; // arrays must be declared with a size, strings are arrays of characters 
    person p; // structs must be declared with a type, structs are used to store multiple variables
    printf("Hello World\n"); //printf is used to print output to the screen
    printf("How old are you?\n");
    scanf("%d", &age); // %d is used to get an integer, & is used to get the address of the variable
    printf("You are %d years old.\n", age); // %d is used to print an integer
    printf("What is your name?\n");
    scanf("%s", name); // scanf is used to get input from the user, %s is used to get a string, name is the array, arrays are addresses so no & needed
    printf("Hello %s!\n", name); // %s is used to print a string, strings are always character arrays
    printf("Whats your favorite number?\n");
    scanf("%lf", &num); // %lf is used to get a double, doubles are floating point numbers
    printf("Your favorite number is %.2f.\n", num); // %.2f is used to print a double with 2 decimal places
    if(age + num < 23) { // if statements require conditions, various operators like <, >, ==, !=
        printf("You are young.\n");
    } else if(age + num <= 40) {
        printf("You're not that old.\n");
    }
    else {
        printf("You are old.\n");
    }
    printf("Let me store you in my database so I can remember you!\n");
    strcpy(p.name, name); // strcpy is used to copy strings, p.name is the struct variable, name is the array
    p.age = age;
    p.favoriteNumber = num;
    printf("I have stored you in my database.\n");
    printf("It was nice to meet you! Bye!\n");
    
    return 0;
}