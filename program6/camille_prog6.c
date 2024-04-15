/******************************************************************************

Jossaya Camille
March 26th, 2024
A program which will allow a user to purchase phones from a list of 8 unique phones which serve different purposes.

*******************************************************************************/

#include <stdio.h>

void Greeting(void); // greets the user
double GetBudget(); // prompts the user to enter their budget
double SetPrice(int itemNumber); // returns the price of a phone given a phone ID 1-8
void DisplayBalance(double balance); // displays the user's remaining balance

void DisplayChoices(char* choice); // prompts the user to enter the list of choices provided, whether to buy a phone or quit the program
void ProcessChoice(char choice, double* budgetPtr, int* numPtr, double* pricePtr); // handles the user's choice; performs requested user action
int DisplayPhones(double budget); // displays the list of phones available to the user
void TryToCheckout(double* budget, double price); // attempts to complete checkout by purchasing the selected phone.


int main()
{
    char choice;
    double budget, price;
    int phone_id;
    Greeting();
    budget = GetBudget();
    DisplayChoices(&choice);
    while(choice != 'q' && choice != 'Q'){
        ProcessChoice(choice, &budget, &phone_id,&price);
        DisplayChoices(&choice);
    }
    return 0;
} 

void Greeting(void) //welcomes the user to Exclusive
{
    char firstInitial, lastInitial;
    printf("Welcome to the Exclusive Phone Store!\n");
    printf("What is your first initial?\n");
    scanf(" %c", &firstInitial);
    printf("What is your last initial?\n");
    scanf(" %c", &lastInitial);
    printf("Hello %c.%c! Purchasing a phone at Exclusive is simple.\n", firstInitial, lastInitial);
    printf("You enter your budget for a phone and we will tell you what phones you can afford.\n");
    printf("You can purchase a phone by entering its corresponding number or by entering -1 for no phone.\n");
    printf("You will have the ability to buy phones until you go broke. Ready?\n");
    printf("Let's begin.\n");
    return;
}

double GetBudget() //asks for the budget amount and returns it to the main function
{
    double budget;
    printf("What is your budget for a phone?\n");
    scanf("%lf", &budget);
    printf("You entered a budget of $%.2f.\n", budget);
    return budget;
    
}
int DisplayPhones(double budget)
{
    // lists all phone options at Exclusive
    // then prompts the user to select a phone by ID, then returns the selected ID to the main function
    int phone_id;
    printf("Here are the phones we offer at Exclusive in your budget:\n");
    if(budget >= 2021) {
        printf("1. nPhone 5: Extra Short Edition...............$2021.00\n");
    }
	if(budget >= 2020) {
        printf("2. t Tab 6: Big Forehead Edition...............$2020.00\n");
    }
    if(budget >= 2023) {
	    printf("3. Dev Phone 5: Missing Tooth Edition..........$2023.00\n");
    }
    if(budget >= 2022) {
	    printf("4. Trap Phone 3: Stuck in Jail Edition.........$2022.00\n");
    }
    if(budget >= 69419.99) {
	    printf("5. Arc Curve 10...............................$69419.99\n");
    }
    if(budget >= 2019) {
	    printf("6. Whiteout 6: Randy McCallister Edition.......$2019.00\n");
    }
    if(budget >= 2023) {
	    printf("7. Revenge Phone 2: Psychopath Edition.........$2023.00\n");
    }
    if(budget >= 10000000) {
	    printf("8. Trap Phone 4: Sandy Jail Edition........$10000000.00\n");
    }
	printf("Which phone would you like?\n");
	scanf("%d",&phone_id);
    return phone_id;
}

//input: item number
//use the item number to identify the price
//display the nasme of the phone and return the price
double SetPrice(int itemNumber) 

// returns the price of a phone given a phone ID
{
    double price;
    if(itemNumber == 1) { // if phone #1 is entered..
        price = 2021;
        printf("You selected the nPhone 5: Extra Short Edition with a price of $%.2f \n",price);
        return price;
    }
    else if (itemNumber == 2) {// if phone #2 is entered..
        price = 2020;
        printf("You selected the t Tab 6: Big Forehead Edition with a price of $%.2f \n",price);
        return price;
    }
    else if (itemNumber == 3) {// if phone #3 is entered..
        price = 2023;
        printf("You selected the Dev Phone 5: Missing Tooth Edition with a price of $%.2f \n",price);
        return price;
    }
    else if (itemNumber == 4) {// if phone #4 is entered..
        price = 2022;
        printf("You selected the Trap Phone 3: Stuck in Jail Edition with a price of $%.2f \n",price);
        return price;
    }
    else if (itemNumber == 5) { // if phone #5 is entered..
        price = 69419.99;
        printf("You selected the Arc Curve 10 with a price of $%.2f\n",price);
        return price;
    }
    else if (itemNumber == 6) { // if phone #6 is entered..
        price = 2019;
        printf("You selected the Whiteout 6: Randy McCallister Edition with a price of $%.2f\n",price);
        return price;
    }
    else if (itemNumber == 7) { // if phone #7 is entered..
        price = 2023;
        printf("You selected the Revenge Phone 2: Psychopath Edition with a price of $%.2f\n",price);
        return price;
    }
    else if (itemNumber == 8) { // if phone #8 is entered..

        price = 10000000;
        printf("You selected the Trap Phone 4: Sandy Jail Edition with a price of $%.2f\n",price);
        return price;
    }
    else if(itemNumber == -1) {
        printf("No phone was selected.");
        return 0;
    }
    else {
        printf("You did not make a proper selection.");
        return 0;
    }
    
}


//input the the budget amount and the phone price
//"purchase" the phone
//subtracts the price from the budget if the purchase was made
//Let’s the user know if the price of the phone is greater than the budget
void TryToCheckout(double* budget, double price)
{
    if(*budget >= price) {
        *budget = *budget - price;
        DisplayBalance(*budget);
    }
    else {
        printf("Unfortunately, you cannot afford this phone with your budget. Get some more bread.\n");
        DisplayBalance(*budget);
    }
    return; 
}


void DisplayBalance(double balance)
{
    printf("Your final balance is $%.2f.\n", balance);
    
    return;
}
//input: the remaining balance
//display the remaining balance
//this function will be called from the TryToCheckout function

void DisplayChoices(char* choice) {
    printf("**********************\n");
    printf("Enter (s or S) to select a phone \n");
    printf("Enter (u or U) to update your budget \n");
    printf("Enter (c or C) to checkout \n");
    printf("Enter (q or Q) to quit \n");
    printf("**********************\n");
    scanf(" %c", choice);
    return;
}

void ProcessChoice(char choice, double* budgetPtr, int* numPtr, double* pricePtr) {
    if(choice == 'S' || choice == 's') {
            printf("Select the phone\n");
            *numPtr = DisplayPhones(*budgetPtr);
            *pricePtr = SetPrice(*numPtr);
        }
    else if(choice == 'u' || choice == 'U') {
            printf("Update your budget\n");
            *budgetPtr = GetBudget();
        }
    else if(choice == 'c' || choice == 'C') {
            TryToCheckout(budgetPtr, *pricePtr);
        }
    else if(choice == 'q' || choice == 'Q') {
            printf("Thank you for shopping with Exclusive! We hope you have a good rest of your day.");
        }
    else {
            printf("Not recognized\n");
        }
    return;
}