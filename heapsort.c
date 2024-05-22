#include <stdio.h>

void max_heapify(int i, int arr[], int n);

void heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(i, arr, n);
    }
    for (int j = n; j > 1; j--)
    {
        int temp = arr[1];
        arr[1] = arr[j];
        arr[j] = temp;
        n = n - 1;
        max_heapify(1, arr, n);
    }
}

void max_heapify(int i, int arr[], int n)
{
    int left, right, maxindex;
    while (1)
    {
        left = 2 * i;
        right = 2 * i + 1;
        maxindex = i;
        if (left <= n && arr[left] > arr[maxindex])
        {
            maxindex = left;
        }
        if (right <= n && arr[right] > arr[maxindex])
        {
            maxindex = right;
        }
        if (maxindex != i)
        {
            int temp = arr[i];
            arr[i] = arr[maxindex];
            arr[maxindex] = temp;
            i = maxindex;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);

    printf("Sorted array: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
