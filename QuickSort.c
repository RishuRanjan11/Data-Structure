#include <stdio.h>

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = arr[start];
        int i = start - 1;
        int j = end + 1;

        do
        {
            do
            {
                i++;
            } while (arr[i] < pivot);

            do
            {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
            {
                break;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } while (i < j);

        quickSort(arr, start, j);
        quickSort(arr, j + 1, end);
    }
}

void printArray(int arr[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[50], n;

    // Input array size and elements
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n != 0)
    {

        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }

        printf("Original array: \n");
        printArray(arr, n);

        quickSort(arr, 0, n - 1);

        printf("Sorted array: \n");
        printArray(arr, n);
    }
    else
        printf("No values to be sorted !");
    return 0;
}
