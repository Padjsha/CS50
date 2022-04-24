#include <cs50.h>
#include <stdio.h>
#include <string.h> //strlen
#include <ctype.h>
#include <stdlib.h> //atoi

int main(int argc, string argv[])
{
    
    if (argc != 2 || argv[1][0] == '-') //just needs one key
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        for (int i = 0, lengthOfKey = strlen(argv[1]) ; i < lengthOfKey ; i++) //control if there is alphabetic %c in key
        {
            if ( argv[1][i] < '0' || argv[1][i] > '9' )
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    }
    int key = atoi(argv[1]); //atoi func makes string to be int
    key %= 26; //

    string plainText = get_string("Plain text: ");
    printf("Cypher text: ");

    for (int i = 0, lengthOfText = strlen(plainText) ; i < lengthOfText ; i++)
    {
        if ( isalpha(plainText[i]) )
        {
            while (plainText[i] >= 'A' && plainText[i] <= 'Z') //isupper
            {
                if (plainText[i] + key > 90) //better: ( plainText[i] - 65 + k ) % 26 + 65
                    printf("%c", plainText[i] + key - 26);
                else
                    printf("%c", plainText[i] + key);
                
                break;
            }

            while (plainText[i] >= 'a' && plainText[i] <= 'z') //islower
            {
                if (plainText[i] + key > 122) //better: ( plainText[i] - 97 + k ) % 26 + 97
                    printf("%c", plainText[i] + key - 26);
                else
                    printf("%c", plainText[i] + key);
                
                break;
            }
        }
      
        else
            printf("%c", plainText[i]);
      
    }
    printf("\n");
}
