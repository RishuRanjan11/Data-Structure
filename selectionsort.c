#include <stdio.h>
void selectionSort(int arr[50], int n) // Function of selection sort
{
    int min, minIndex;
    int temp, j, i;
    for (i = 0; i < n - 1; i++)
    {
        min = arr[i];
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main(int argc, char const *argv[])
{
    // Input of array

    int n, arr[50];
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
    else
        printf("No values to be sorted !");

    selectionSort(arr, n); // calling function

    // Display of sorted array

    if (n != 0)
    {
        printf("Sorted array: \n[ ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("]");
    }

    return 0;
}
