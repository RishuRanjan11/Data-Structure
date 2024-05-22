#include <stdio.h>

void insertionSort(int arr[50], int n) // Function of insertion sort
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {

                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            else
                break;
            j--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n, arr[50];

    // Input of array

    printf("Enter the size of an array. \n");
    scanf("%d", &n);

    if (n != 0)
    {
        printf("Enter the values of array: \n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    insertionSort(arr, n); // Calling of function

    // Disply of sorted array
    if (n != 0)
    {
        printf("Sorted array:\n[ ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf(" ]");
    }
    else
        printf("No values to be sorted !");

    return 0;
}
