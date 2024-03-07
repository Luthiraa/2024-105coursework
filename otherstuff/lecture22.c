#include <stdio.h>
#include <stdlib.h>
// 2d arrays
// stored in "row major order" in the memory -
//      int arr[][3];
//      arr[0][0];
//      arr[0][1];
//       so on, so goes row by row, filling in the columns
//        ----

int sum2d(int sizeColumns, int arr[][sizeColumns], int sizeRows);
int sum2dptr(int sizeColumns, int arr[][sizeColumns], int sizeRows);
int main(void)
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        };
    int numCols = 3;         // number of columns so 3 in this case
    // printf("%d\n", arr + 1); // address of a[0][1] so &a[0][1]

    // // general expression to get any eleent of an array in any row is
    // int i, j; // where i is the index of the row and j is the index of the column
    // printf("%d\n", arr + (i * numCols + j));

    // to get the 2rd element in the 2nd row:
    printf(" try this one: %d", *(arr+(2*numCols+1)));

    int arr2d[2][3] = {1, 2, 3, 4, 5, 6};

    int sizecols = 2;
    int sizerows = 3;
    int sum = sum2d(sizecols, arr2d, sizerows);
    printf("\n%d", sum);
    int sumptr = sum2dptr(sizecols, arr2d, sizerows);
    printf("\n%d", sumptr);
}

// have to initilzie the arguremnt before referencing it so sizeColumns must be defined before
int sum2d(int sizeColumns, int arr[][sizeColumns], int sizeRows)
{
    int sum = 0;
    for (int i = 0; i < sizeRows; i++)
    {
        for (int j = 0; j < sizeColumns; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int sum2dptr(int sizeColumns, int arr[][sizeColumns], int sizeRows)
{
    int sum = 0;
    for (int i = 0; i < sizeRows; i++)
    {
        for (int j = 0; j < sizeColumns; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }
    return sum;
}