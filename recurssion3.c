#include<stdio.h>

int sumOfSeries(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + sumOfSeries(n-1);
    }
}

int main(int argc, char const *argv[]) {
    int n, sum;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    sum = sumOfSeries(n);
    printf("Sum = %d\n", sum);
    return 0;
}
