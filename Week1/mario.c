#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do 
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    for (int i = 0 ; i < height ; i++) //i for row
    {
        for (int j = height -1 ; j > i ; j--) //j for (space)
        {
            printf(" ");
        }

        for (int k = 0 ; k <= i ; k++) //k for (#)
        {
            printf("#");
        }
        printf("\n");
    }
}
