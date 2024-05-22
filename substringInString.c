// WAP to find wehter the substring is present in main string or not
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int i, j = 0, count = 0, k, length, subLength;
    char string[50], subString[50];
    // Input of main string
    printf("Enter a string: ");
    gets(string);
    length = strlen(string);

    // Input of subString
    printf("Enter the substring: ");
    gets(subString);
    subLength = strlen(subString);
    for (j = 0; j < length - subLength + 1; j++)
    {

        if (subString[0] == string[j])
        {
            for (i = 0; i < subLength; i++)
            {
                if (subString[i] == string[j + i])
                    continue;
                else
                    break;
            }
            if (i == subLength)
            {
                printf("Given subString is present from index %d to %d\n", j, j + subLength - 1);
                count++;
            }
        }
    }
    printf("Total count is %d", count);
    return 0;
}
