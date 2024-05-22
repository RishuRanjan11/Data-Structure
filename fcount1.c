#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fpout;
    int n;
    char val;
    fpout = fopen("output.txt", "wt");
    printf("Enter the total number of chars: ");
    scanf("%d", &n);
    fprintf(fpout, "%d ", n);
    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c ", &val);
        fprintf(fpout, "%c ", val);
    }

    fclose(fpout);
    return 0;
}
