#include <stdio.h>

#define SIZE 50


//input array of type integer, will return the number of filled cells
int FillIntArray(int ar[], int capacity);
void PrintIntArray(int ar[], int count);
int main() {
    int apple[SIZE*2]; // size of 20
    int aCount = 0; //count of zero

    int banana[20] = {11, 12, 13, 14, 15}; //index 0,1,2,3,4
    int bCount = 5; // number of items


    
    // items must be added to arrays either on declaration or individual through indexes

    apple[0] = 101;
    aCount++; 

    // apple = {1,2,3,4,5} is not possible though C
    aCount = FillIntArray(apple,100); //running FillIntArray will overwrite the first index
    bCount = FillIntArray(banana,20); 
    PrintIntArray(apple, aCount);
    PrintIntArray(banana, bCount);
    return 0;
}


void PrintIntArray(int ar[], int count) {
    int i;
    for(i=0;i<count;i++) {
        printf("%d\n",ar[i]); //loops through an array printing at every index
    }
    return;
}
int FillIntArray(int ar[], int capacity) {
    int count, i;
    do{
        printf("How many integers? (up to %d)\n",capacity); //prompts the user to enter how many integers are they entering
        scanf("%d",&count);
    }while(count < 1 || count > capacity); // checks if the user entered at least 1 and that their number of integers
    // does not exceed capacity
    for(i=0;i<count; i++) {
        printf("Enter an integer for index %d\n",i);
        scanf("%d",&ar[i]); //scans an integer into the array at index i
    }
    return count;
}
