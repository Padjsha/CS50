#include <cs50.h> //Promts name and greets with it.
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}
