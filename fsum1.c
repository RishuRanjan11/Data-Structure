#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fpout;
    int n, val;
    fpout = fopen("output.txt", "wt");
    printf("Enter the size of data: ");
    scanf("%d", &n);
    fprintf(fpout, "%d ", n);
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        fprintf(fpout, "%d ", val);
    }
    fclose(fpout);
    return 0;
}
