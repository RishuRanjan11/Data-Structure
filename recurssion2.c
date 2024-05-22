#include <stdio.h>

void series(int n) {
    if (n > 1) {
        series(n - 1);
    }
    printf("%d ", n);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    series(n);
    return 0;
}
