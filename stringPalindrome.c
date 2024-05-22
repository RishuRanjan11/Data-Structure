// WAP a program to find wether the given string is palindrome or not
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char string[50], revString[50];
    int i, length;
    printf("Enter a string: \n");
    gets(string);
    length = strlen(string); // finds length of string

    // Reversing the string
    for (i = 0; i <= length; i++)
    {
        revString[i] = string[length - i - 1];
    }

    // comparing the initial string and reversed string
    for (i = 0; i <= length; i++)
    {
        if (revString[i] == string[i])
            continue;
        else
            break;
    }

    // displaying result after checking for palindrome
    if (i == length)
    {
        printf("Given string is palindrome.");
    }
    else
        printf("Given string is not palindrome.");
    return 0;
}
