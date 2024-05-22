#include <stdio.h>

void merge(int arr[50], int start, int mid, int end);

void mergesort(int arr[50], int start, int end)
{
   
    if (end - start > 1)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    
}

void merge(int arr[50], int start, int mid, int end)
{
    int temp[50];
    int i = start, j = mid, k = 0;

    while (i <= mid && j >= start)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else if (arr[j] < arr[i])
        {
            temp[k] = arr[j];
            j--;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    k = 0;
    for (i = start; i <= end; i++)
    {
        arr[i] = temp[k];
        k++;
    }
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

        // Perform mergesort
        mergesort(arr, 0, n - 1);

        // Display sorted array
        printf("Sorted array:\n[ ");
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("]\n");
    }
    else
        printf("No values to be sorted !");

    return 0;
}
