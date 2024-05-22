#include <stdio.h>

int findLargest(int arr[], int n) {
    // Base case: If there is only one element, it is the largest
    if (n == 1) {
        return arr[0];
    } else {
        // Recursive case: Compare the first element with the largest of the rest
        int restLargest = findLargest(arr + 1, n - 1);
        if (arr[0] > restLargest) {
            return arr[0];
        } else {
            return restLargest;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input: Number of elements should be positive.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, n);
    printf("The largest number is: %d\n", largest);

    return 0;
}
