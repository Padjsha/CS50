#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char a);

int main(int argc, string argv[])
{
    if (argc == 2 && isalpha(*argv[1])) //'*' is important
    {
        int lengthOfKeyword = strlen(argv[1]);
        
        string plain = get_string("Plain text: ");
        int lengthOfPlain = strlen(plain);
        
        printf("\nCypher text: ");
        for (int i = 0, j = 0; i < lengthOfPlain ; i++) //different counters because it doesn't want to pass the next key char while print space or numbers
        {
            if (isupper(plain[i]))
            {
                printf("%c", ( plain[i] - 'A' + shift(argv[1][j % lengthOfKeyword]) ) % 26 + 'A'); //formula
                j++;
            }   

            else if (islower(plain[i]))
            {
                printf("%c", ( plain[i] - 'a' + shift(argv[1][j % lengthOfKeyword]) ) % 26 + 'a');
                j++;
            }

            else if (isspace(plain[i]))
                printf(" ");

            else //for numeric ones
                printf("%c", plain[i]);
        }
    }

    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

int shift(char a)
{
    if (isupper(a))
        return a - 'A';
    else
        return a - 'a';
}
