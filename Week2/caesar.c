#include <cs50.h>
#include <stdio.h>
#include <string.h> //strlen
#include <ctype.h>
#include <stdlib.h> //atoi

int main(int argc, string argv[])
{
    
    if (argc == 2 && isdigit(*argv[1]) ) //just needs one key (a positive one) & '*' important
    {
        int key = atoi(argv[1]); //atoi func makes string to be int
        
        string plainText = get_string("Plain text: ");
        printf("Cypher text: ");

        for (int i = 0, lengthOfText = strlen(plainText) ; i < lengthOfText ; i++)
        {
            if (isupper(plainText[i]) )   
                printf("%c", (plainText[i] - 'A' + key) % 26 + 'A');
                
            else if (islower(plainText[i]))
                printf("%c", (plainText[i] - 'a' + key) % 26 + 'a');
                     
            else if (plainText[i] == ' ')
                printf(" ");
                   
            else
                printf("%c", plainText[i]);
        }
        printf("\n");        
    }
                    
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
