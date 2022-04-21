#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number, temp;
    int totalOfFirstGroup = 0, totalOfSecondGroup = 0, total, digitsCounter = 0, lastTwoDigits;
    int onlyDigits = 0;

    do
    {
        number = get_long("Credit card number: ");
    } while (number < 0);

    temp = number;

    while (temp > 0)
    {
        totalOfFirstGroup += temp % 10;
        temp /= 10;

        if ((temp % 10 * 2) >= 10)
        {
            onlyDigits = temp % 10 * 2;
            totalOfSecondGroup += onlyDigits % 10;
            onlyDigits /= 10;
            totalOfSecondGroup += onlyDigits;
        } 
        else 
            totalOfSecondGroup += temp % 10 * 2;

        temp /= 10;
    }

    total = totalOfFirstGroup + totalOfSecondGroup;
    if (total % 10 == 0) //number of digits
    {
        temp = number;
        while (temp > 0)
        {
            temp /= 10;
            digitsCounter++;
        }

        temp = number;
        while (temp > 100) //last two digits
        {
            temp /= 10;
        }
        lastTwoDigits = temp;

        switch (digitsCounter) //company control
        {
            case 15:
                if (lastTwoDigits == 37 || lastTwoDigits == 34)
                    printf("AMEX\n");
                    break;

            case 13: 
                if (lastTwoDigits > 39 && lastTwoDigits < 50)
                    printf("VISA\n");
                    break;

            case 16: 
                if (lastTwoDigits > 50 && lastTwoDigits < 56)
                    printf("MASTERCARD\n");
                else if (lastTwoDigits > 39 && lastTwoDigits < 50)
                    printf("VISA\n");
                break;

            default:
                printf("Warning! Fixed Card Number\n");
        }
    }
    else
        printf("INVALID\n");
}
