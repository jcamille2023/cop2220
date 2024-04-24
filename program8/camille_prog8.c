
/* name, date, brief description STUDENT 1
 */


#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#define SIZE 40

typedef struct{
 char name[SIZE];
 char color[SIZE];
 double weight;
}reptile;

//Function Prototypes

// fills the data fields of a reptile instance
//returns the filled reptile
reptile FillReptile();

//fills the data fields of a reptile instance
//by reference using a pointer to a reptile
void FillReptilePtr(reptile *reptilePtr);

//fills an array of reptiles
void FillReptileArray(reptile reptileList[], int *size);


//displays one reptile
void DisplayReptile(reptile anyReptile);

int main()
{
    //Declare variables
	reptile myReptile, myReptile1, myReptile2;
	reptile manyReptiles[SIZE];
	int cSize;
	int i;

	//Fill structures with a function
	myReptile1 = FillReptile();
	myReptile = FillReptile();

	//print using display function
	printf("\n---------Display myReptile\n");
	DisplayReptile(myReptile);
	printf("\n---------Display myReptile1\n");
	DisplayReptile(myReptile1);

	//Fill structure using pointers and dispay it
	FillReptilePtr(&myReptile2);
	printf("\n---------Display myCard2\n");
	DisplayReptile(myReptile2);

	//Fill the array with the function
	printf("\n---------Fill array manyCards\n");
	FillCardArray(manyReptiles, &cSize);

	//display an array of cards
	printf("\n---------Display array manyCards\n");
	for(i=0;i<cSize; i++)
	{
		DisplayCard(manyReptiles[i]);
	}
	return 0;
}

//Function Definitions

reptile FillReptile() {
    reptile new_rept;
    printf("Enter the name of your reptile:\n");
    scanf(" %s",&new_rept.name);
    printf("Enter the color of your reptile: \n");
    scanf(" %s", &new_rept.color);
    printf("Enter the weight of your reptile: \n");
    scanf("%lf", &new_rept.weight);
    return new_rept;
}

void displayReptile(reptile rept1) {
    int len1, len2, n;
    len1 = strlen(rept1.name);
    len2 = strlen(rept1.color);
    printf("Name: ");
    for(n = 0; n < len1; n++) {
        printf("%c", rept1.name[n]);
    }
    printf("\n");
    printf("Color: ");
    for(n = 0; n < len1; n++) {
        printf("%c", rept1.color[n]);
    }
    printf("\n");
    printf("Weight: %.2f\n", rept1.weight);

    return; 
}

