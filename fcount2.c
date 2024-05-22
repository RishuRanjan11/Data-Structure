#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fpin;
    int n;
    char val;
    int digit = 0, alpha = 0, schar = 0;
    fpin = fopen("output.txt", "rt");
    fscanf(fpin, "%d ", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fpin, "%c ", &val);
        if (val >= 48 && val <= 57)
            digit++;
        else if (val >= 65 && val <= 90 || val >= 97 && val <= 122)
            alpha++;
        else
            schar++;
    }
    fclose(fpin);
    printf("digits: %d , alphabets: %d , Special characters: %d", digit, alpha, schar);
    return 0;
}
