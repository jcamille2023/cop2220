
//COP 2220 spring 2024 Program 9
//add name, date and a brief description here

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include <stdio.h>
#include <ctype.h> //for toupper and tolower

#define SIZE 50

typedef struct {
    char OrderName[50]; //stores the first name of the customer
    int OrderNumber; //stores the order number of the customer
    double OrderAmount; //stores the order amount
    char location[100]; //stores the customer’s location
    char validOrder;//stores 'V' for valid or 'I' invalid
} customer;

//(1)greet the user
void Greeting();

//(2)fill the inventory with five customers
void FillFive(customer inventory[]);

//(3)Display the menu, ask, get, and return the user choice
char GetChoice();

//(4)run the program menu (process the choice)
//use if else conditions (or switch)
void ProcessMenu(char choice, customer inventory[], int *countPtr);

//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info);

//(6)print entire VALID customer inventory onto the screen
void PrintValidList(customer inventory[], int count);

//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count);

//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count);

//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count);

//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count);



int main()
{
    //declare character for the choice
    char choice;

    //declare an array of 50 customers (inventory )
    customer inventory[50];
 
    //declare count for the array
    int count;
  
    //greet the user
    Greeting();
  
    //fill five customers into the array
    FillFive(inventory);
    //set count to 5
     count = 5;
   
    printf("\nFIVE Valid customers have been added to the inventory.\n\n");

    //get the choice - initialization
   choice = GetChoice();
    while (choice != 'Q')
    {
        ProcessMenu(choice, inventory, &count);
        choice = GetChoice(); //update
    }

    printf("\nHave a great day!");
    return 0;
}

//(1)greet the user

//(2)fill the inventory with five customers
void FillFive(customer inventory[])
{
    customer temp1 = { "Iron.Man", 1, 23567843567.99, "Malibu", 'V' };
    inventory[0] = temp1;
    customer temp2 = { "Jossaya", 2, 4.19, "Boynton Beach", 'V' };
    inventory[1] = temp2;
    customer temp3 = { "Amarnath", 3, 5.00, "Boynton Beach", 'I' };
    inventory[2] = temp3;
    customer temp4 = { "Thandi", 4, 15.00, "Boynton Beach", 'I' };
    inventory[3] = temp4;
    customer temp5 = { "Zach", 5, 1000000.69, "Wellington", 'I' };
    inventory[4] = temp5;
    return;

}

//(3)Display the menu, ask, get, and return the user choice

//(4)run the program menu (process the choice)
//use if else conditions (or switch)
void ProcessMenu(char choice, customer inventory[], int* countPtr)
{
    if (choice == 'A')
    {
        *countPtr = *countPtr + 1;
        AddCustomerToList(inventory, *countPtr);
        
    }
    else if (choice == 'P')
    {   
        int number = 0;
        printf("\nThere are %d orders\n", *countPtr);
        //use a loop to make sure the user enters a valid order number
        do{
            //declare ask and get the order number
            printf("What is the order number?\n");
            scanf("%d", &number);
        }while(number<*countPtr);
        PrintOneCustomer(inventory[number - 1]);
    }
    else if (choice == 'V')
    {
        //call the print valid inventory function
        PrintValidList(inventory,*countPtr);
    }
    else if (choice == 'C')
    {
        printf("Creating a report");
        //call print file function
        PrintListToFile(inventory,*countPtr);
    }
    else if (choice == 'I')
    {
        //call make invalid function
        MakeInvalid(inventory,*countPtr);
    }
    else if (choice == 'E')
    {
        double amount;
        int n;
        customer person;
        //ask and get the amount
        printf("What will the minimum amount be?\n");
        scanf("%lf",&amount);
        //loop through the array to display
        for(n = 0;n<*countPtr;n++) {
            person = inventory[n];
            if(person.OrderAmount>=amount) {
                PrintOneCustomer(person);
            }
        }
    }
    else if (choice == 'T')
    { 
        
    }
    else printf("\nNot valid");

}



//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info)
{
    printf("\n---------------------------------------\n");
    printf("\nOrder number:\t\t%d", info.OrderNumber);
    printf("\nOrder name: %s", info.OrderName);
    printf("\nOrder amount: $%.2f", info.OrderAmount);
    printf("\nLocation: %s", info.location);
    printf("Valid order: %c", info.validOrder);
}

//(6)print entire VALID customer inventory onto the screen
void PrintValidList(customer inventory[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (inventory[i].validOrder == 'V')
        {
            PrintOneCustomer(inventory[i]);
        }
    }

}

//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count)
{
    FILE* outPtr;
    outPtr = fopen("report.txt", "w");
    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(outPtr,"\n---------------------------------------\n");
        fprintf(outPtr,"\nOrder number:\t\t%d", inventory[i].OrderNumber);
        fprintf(outPtr,"\nOrder name:\t\t %s", inventory[i].OrderName);
        fprintf(outPtr, "\nOrder amount: \t\t$%.2f", inventory[i].OrderAmount);
        fprintf(outPtr,"\nLocation: \t\t%s", inventory[i].location);
        fprintf(outPtr,"Valid order: \t\t%c", inventory[i].validOrder);
        //add the rest
    }
    fclose(outPtr);
}

//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count)
{
    //set the order number based on the count
    inventory[count].OrderNumber = count + 1;

    //get the name
    printf("Please enter the name of the order: ");
    scanf(" %s", inventory[count].OrderName);

    printf("Please enter the amount of the order: ");
    scanf(" %lf", &inventory[count].OrderAmount);

    printf("Please enter the location of the order: ");
    scanf(" %s", inventory[count].location);
    
    //add the additional prompts and scanf statements

    //set the order as valid
    inventory[count].validOrder = 'V';

}

//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count)
{
    printf("\nThere are %d orders\n", count);
    //declare ask and get the order number
    int number = 0;

    do{
        inventory[number].validOrder = 'I';
        number++; 
    }while(number < count);
    //order number is one greater than the index, examples:
    //index is 0 - order number is 1
    //inedx is 1 - order number is 2
}


//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count)
{
    int i, totalCount = 0;
    double sum = 0.0, avg;
    int n;
        double total, average;
        //calculate the total and the average
        for(n = 0;n<count;n++) {
            if(inventory[n].validOrder == 'V') {
                sum += inventory[n].OrderAmount;
                totalCount += 1;
            }
        }
        average = total / totalCount;
        printf("The total amount purchased by all customers is $%.2f.", total);
        printf("The average purchase by each customer is $%.2f.", average);
}


void Greeting()
{
    printf("Welcome to the Customer Order Program\n");
    printf("This program will allow you to add, print, and manipulate customer orders.\n");
    printf("You can also create a report of all the orders.\n");
    printf("Let's get started!\n");
}

char GetChoice()
{
    char choice;
    printf("\n\nPlease choose from the following options:\n");
    printf("A - Add a new customer\n");
    printf("P - Print one customer\n");
    printf("V - Print all valid customers\n");
    printf("C - Create a report\n");
    printf("I - Make a customer invalid\n");
    printf("E - Print all customers with an amount greater than a certain amount\n");
    printf("T - Calculate the total and the average of all the valid orders\n");
    printf("Q - Quit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return toupper(choice);
}