#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float change;
    int convertedValue; //needed to avoid floating imprecision which causes errors in calculation
    int qtyOfCoins = 0;

    do
    {
        change = get_float("How much change is owed? \n");
        convertedValue = round(change * 100); //needed to avoid floating point imprecision which causes errors in calculation
    }

    while (change < 0);

    //printf("%.2f", change);
    //printf("\n");
    while (convertedValue >= 25)
    {
        convertedValue = convertedValue - 25;
        qtyOfCoins++;

    }
    while (convertedValue < 25 && convertedValue >= 10)
    {
        convertedValue = convertedValue - 10;
        qtyOfCoins++;
    }
    while (convertedValue < 10 && convertedValue >= 05)
    {
        convertedValue = convertedValue - 5;
        qtyOfCoins++;
    }

    while (convertedValue < 5 && convertedValue > 0)
    {
        convertedValue = convertedValue - 1;
        qtyOfCoins++;
    }
    printf("%i", qtyOfCoins);
    printf("\n");
}