#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarter = 0, dime = 0, nickel = 0, penny = 0; //counters
    float cash;

    do
    {
        cash = get_float("Amount of money: ");
    } while (cash < 0);

    int cents = round(cash*100);

    while (cents > 0)
    {
        if (cents > 25)
        {
            quarter = cents / 25;
            cents %= 25;
        }

        if (cents > 10)
        {
            dime = cents / 10;
            cents %= 10;
        }

        if (cents > 5)
        {
            nickel = cents / 5; 
            cents %= 5;
        }
        if (cents > 1)
        {
            penny = cents / 1;
            cents %= 1;
        }
    }

    printf("Payback done\n");
    printf("Payback: %.2f\n", cash);
    printf("Total coin: %i\n", quarter + dime + nickel + penny);
    printf("%ix quarter, %ix dime, %ix nickel, %ix penny\n", quarter, dime, nickel, penny);
}
