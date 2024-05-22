#include<stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fpin;
    int sum=0;
    int n, val;
    fpin = fopen("output.txt", "rt");
    fscanf(fpin, "%d ",&n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fpin, "%d ", &val);
        sum+=val;
    }
    
    fclose(fpin);
    printf("%d" , sum);
    return 0;
}
