#include<stdio.h>
#include<malloc.h>

#define MAX 2000000000

void printMatrix(int **matrix, int size)
{
    printf("\n\nPRINTING MATRIX.   \n\n");
    int i,j;
        for(i = 0; i < size; ++i)
        {
            for(j = 0; j < size; ++j)
            {
                if(matrix[i][j] == 2000000000)
                    printf("<><>\t");
                else
                    printf("%d \t",matrix[i][j]);
            }
            printf("\n");
        }
}

void PRINT_OPTIMAL_PARENS(int **s, int i, int j )
{

    if(i == j)
        printf("-A%d-",i);
    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s, s[i][j], j);
        printf(")");
    }
}


int mincost2(int *p, int n)
{
    int currentRow, currentColumn;
    int **mat = (int **)malloc((n+1)*sizeof(int *));
    for(currentRow = 0; currentRow <= n; ++currentRow)
        mat[currentRow] = (int *)malloc((n+1)*sizeof(int));

    for(currentRow = 0; currentRow <= n ; ++currentRow)
        for(currentColumn = 0; currentColumn <= n; ++currentColumn)
            mat[currentRow][currentColumn] = 0;

    int startingCol,cutPoint;
    for(startingCol = 2; startingCol <= n; ++startingCol)
    {
        for(currentRow = 0, currentColumn = startingCol; currentColumn <= n; ++currentRow, ++currentColumn)
        {
            mat[currentRow][currentColumn] = MAX;
            int temp;
            for(cutPoint = currentRow + 1; cutPoint < currentColumn; ++cutPoint)
            {
                temp = mat[currentRow][cutPoint] + mat[cutPoint][currentColumn] + (p[currentRow] * p[cutPoint] * p[currentColumn]);
                if(temp < mat[currentRow][currentColumn])
                    mat[currentRow][currentColumn] = temp;
            }
        }
    }
    int minimumCost = mat[0][n],i;

    for(i = 0; i <= n; ++i)
        free(mat[i]);
    free(mat);

    return minimumCost;

}

int minCost(int *p,int n)
{
    int **mat = (int **)malloc((n+1)*sizeof(int *));
    int i,j;
    for(i = 0; i <= n; ++i)
        mat[i] = (int *)malloc((n+1)*sizeof(int));

    for(i = 0; i <= n; ++i)
        for(j = 0; j <=n; ++j)
            mat[i][j] = 0;

/*
    int **cutMat = (int **)malloc((n+1)*sizeof(int *));
    for(i = 0; i < n+1; ++i)
        cutMat[i] = (int *)malloc((n+1)*sizeof(int));

    for(i = 0; i < n+1; ++i)
        for(j = 0; j <n+1; ++j)
            cutMat[i][j] = 0;
*/
   // printMatrix(mat,n+1);

int startingCol, startingRow, cutPoint, currentCol,temp;
    for(startingCol = 2; startingCol <= n; ++startingCol)
    {
        currentCol = startingCol;
        for(startingRow = 0; currentCol <= n; ++startingRow, ++currentCol)
        {
            mat[startingRow][currentCol] = 1000000007; //or highest number possible to denote infinity.
            for(cutPoint = startingRow+1 ; cutPoint < currentCol; ++cutPoint)
            {
                    temp = ( mat[startingRow][cutPoint] + mat[cutPoint][currentCol] )+ ( p[startingRow] * p[cutPoint] * p[currentCol]);
                    if(mat[startingRow][currentCol] > temp)
                        {
                            mat[startingRow][currentCol] = temp;
                          //  cutMat[startingRow][currentCol] = cutPoint;
                        }
            }
        }
    }
    printMatrix(mat,n+1);

    int mincost = mat[0][n];

    //freeing the matrix memory
    for(i = 0; i <= n; ++i)
        free(mat[i]);
    free(mat);

    /*
    // printMatrix(cutMat,n+1);
    printf("\n");
    //PRINT_OPTIMAL_PARENS(cutMat,0,n-1);
     //freeing the matrix memory
    for(i = 0; i <= n; ++i)
        free(cutMat[i]);
    free(cutMat);
*/

    return mincost;
}

int main()
{
    FILE *fptr = fopen("matrixChainMultiplicationInput.txt","r");
    int n;
    fscanf(fptr,"%d",&n);
    printf("\nThere are %d matrix with elements :.\n",n);
    int *p = (int *)malloc((n+1)*sizeof(int));
    int i =0;
    while(i<=n)
    {
        fscanf(fptr,"%d",&p[i]);
        printf("%d ",p[i++]);
    }

    fclose(fptr);
    printf("\nMin cost is %d.",minCost(p,n));

    printf("\nMin cost is %d.",mincost2(p,n));

free(p);
return 0;
}
