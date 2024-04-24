#include <stdio.h>

#define size 50
typedef struct { //structure of the jewel
    char name[size];
    char color[size];
    double weight;
    double price;
}jewel;

jewel GetJewel();

int main() {
    jewel newJewel;
    newJewel = GetJewel();
    return 0;
}

jewel GetJewel() {
    jewel newJewel;
    printf("Enter the name of the jewel: \n");
    scanf("%s", newJewel.name);
    printf("Enter the color of the jewel: \n");
    scanf("%s", newJewel.color);
    printf("Enter the weight of the jewel: \n");
    scanf("%lf", &newJewel.weight);
    printf("Enter the price of the jewel: \n");
    scanf("%lf", &newJewel.price);
    return newJewel;
}