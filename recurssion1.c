#include <stdio.h>
int series(int n)
{
    if (n != 1)
    {
        printf("%d\t", n);
        return series(n - 1);
    }
    else
    {
        printf("%d",n);
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    series(n);
    return 0;
}
