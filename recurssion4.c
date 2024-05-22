#include<stdio.h>

int sumOfSeries(int n) {
    if(n == 0) {
        return 1; // Base case: when n = 0, return 1
    } else {
        return (1 << n) + sumOfSeries(n - 1); // Recursively calculate the sum
    }
}

int main(int argc, char const *argv[]) {
    int n, sum;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    
    // Validate input: n should be non-negative
    if(n < 0) {
        printf("Invalid input: n should be non-negative.\n");
        return 1; // Exit with error code
    }
    
    sum = sumOfSeries(n);
    printf("Sum = %d\n", sum);
    return 0;
}
