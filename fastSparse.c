#include <stdio.h>

typedef struct Term
{
    int row;
    int col;
    int val;
} Term;

void inputMatrix(Term );

int main()
{
    // Input Sparse Matrix
    struct Term sparseA[100];
    

    printf("Enter the number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &sparseA[0].row, &sparseA[0].col, &sparseA[0].val);

    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 1; i <= sparseA[0].val; i++)
    {
        printf("Element %d: ", i);
        scanf("%d %d %d", &sparseA[i].row, &sparseA[i].col, &sparseA[i].val);
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 1; i <= sparseA[0].val; i++)
    {
        printf("(%d, %d, %d) ", sparseA[i].row, sparseA[i].col, sparseA[i].val);
        printf("\n");
    }
    printf("\n");

    // Fast Transpose the matrix
    struct Term transpose[100];
    int rowTerm[sparseA[0].col];
    int startingIndex[sparseA[0].col + 1];

    // Initialize rowTerm and startingIndex
    for (int i = 0; i < sparseA[0].col; i++)
    {
        rowTerm[i] = 0;
    }

    // Count the number of non-zero elements in each column
    for (int i = 1; i <= sparseA[0].val; i++)
    {
        rowTerm[sparseA[i].col]++;
    }

    // Calculate the starting index for each column
    startingIndex[0] = 0;
    for (int i = 1; i <= sparseA[0].col; i++)
    {
        startingIndex[i] = startingIndex[i - 1] + rowTerm[i - 1];
    }

    // Perform fast transpose
    for (int i = 1; i <= sparseA[0].val; i++)
    {
        int index = startingIndex[sparseA[i].col];

        transpose[index].row = sparseA[i].col;
        transpose[index].col = sparseA[i].row;
        transpose[index].val = sparseA[i].val;

        startingIndex[sparseA[i].col]++;
    }

    // Display the transposed matrix
    printf("\nFast Transposed Matrix:\n");
    for (int i = 0; i < sparseA[0].val; i++)
    {
        printf("(%d, %d, %d) ", transpose[i].row, transpose[i].col, transpose[i].val);
        printf("\n");
    }

    return 0;
}
