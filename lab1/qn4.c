// product of two matrices using DMA

#include <stdio.h>
#include <stdlib.h>

void getData(int *mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i * col + j]);
        }
    }
}

void print(int *mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", mat[i * col + j]);
        }
        printf("\n");
    }
}

int *mul(int *mat1, int *mat2, int row, int col1, int col2)
{
    int *rslt = (int *)calloc(row, col2 * sizeof(int));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col2; j++) // col2 of mat2
        {
            for (int k = 0; k < col1; k++) // col1 of mat1
            {
                rslt[i * col2 + j] += mat1[i * col1 + k] * mat2[k * col2 + j];
            }
        }
    }
    return rslt;
}

int main()
{
    int row, col1, col2;
    printf("Row 1: ");
    scanf("%d", &row);

    printf("Col1: ");
    scanf("%d", &col1);

    // row of matrix 2 = col of matrix 1
    printf("Col2: ");
    scanf("%d", &col2);

    int *matrix1 = (int *)calloc(row, col1 * sizeof(int));
    int *matrix2 = (int *)calloc(col1, col2 * sizeof(int));

    getData(matrix1, row, col1);
    getData(matrix2, col1, col2);

    printf("matrix1: \n");
    print(matrix1, row, col1);
    printf("\n\nMatrix2: \n");
    print(matrix2, col1, col2);

    int *rslt = (int *)calloc(row, col2 * sizeof(int));
    rslt = mul(matrix1, matrix2, row, col1, col2);
    printf("\nMultiplication : \n");
    print(rslt, row, col2);

    free(rslt);
    free(matrix1);
    free(matrix2);
    return 0;
}