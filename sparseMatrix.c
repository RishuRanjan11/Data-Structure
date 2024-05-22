#include <stdio.h>

typedef struct term
{
    int row;
    int col;
    int val;
} term;

int main()
{
    int count, k;
    struct term sparseA[100];
    struct term transpose[100];
    int rows, cols;

    // printf("Enter number of rows, columns and non-zero value: ");
    // scanf("%d%d%d", &sparseA[0].row, &sparseA[0].col, &sparseA[0].val);

    // Input normal matrix

    printf("Enter the number of rows and cols: \n");
    scanf("%d%d", &rows, &cols);
    int matrix[rows][cols];
    k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the values of %d row, %d col: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                sparseA[k].row = i;
                sparseA[k].col = j;
                sparseA[k].val = matrix[i][j];
                k++;
            }
            
        }
    }

    // Input Sparse Matrix

    // printf("Enter row, column, and value for each non-zero element:\n");
    // for (int i = 1; i <= sparseA[0].val; i++)
    // {
    //     printf("row,col,element: ");
    //     scanf("%d %d %d", &sparseA[i].row, &sparseA[i].col, &sparseA[i].val);
    // }

    // Display the original matrix
    printf("Original matrix: ");
    for (int i = 1; i <= sparseA[0].val; i++)
    {
        printf("%d %d %d", sparseA[i].row, sparseA[i].col, sparseA[i].val);
        printf("\n");
    }

    // Transpose the matrix
    transpose[0].row = sparseA[0].col;
    transpose[0].col = sparseA[0].row;
    transpose[0].val = sparseA[0].val;

    count = sparseA[0].val;
    k = 1;
    for (int col_no = 0; col_no < sparseA[0].col; col_no++)
    {
        for (int i = 0; i <= count; i++)
        {
            if (sparseA[i].col == col_no)
            {
                transpose[k].row = sparseA[i].col;
                transpose[k].col = sparseA[i].row;
                transpose[k].val = sparseA[i].val;
                k++;
            }
        }
    }

    // Display the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int k = 1; k <= transpose[0].val; k++)
    {
        printf("(%d, %d, %d) ", transpose[k].row, transpose[k].col, transpose[k].val);
        printf("\n");
    }

    return 0;
}
