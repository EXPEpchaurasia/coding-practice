#include<stdio.h>
#include<malloc.h>

int count = 0;

void printSolution(int **chess,int n)
{
    int i,j;
    printf("\n");
    for(i = 0; i < n;++i)
    {
        for(j = 0 ; j < n; ++j)
        {
            if(chess[i][j]== -1)
                printf("Q  ");
            else
                printf("_  ");
        }
        printf("\n");
    }
}

void nQueen(int **chess, int n, int currRow)
{

    if(currRow == n)    //if solution is found, then print it
    {
        printSolution(chess,n);
        count ++;
        return;
    }
    else
    {
        int currentColumn = 0,k,j;
        for(currentColumn = 0; currentColumn < n; ++currentColumn)
        {
            if(!(chess[currRow][currentColumn]))//if the cell is unoccupied and valid to occupy
            {
                chess[currRow][currentColumn] = -1; //occupy the cell

                for(k = currentColumn+1; k < n; ++k)   //updating current column downwards
                    ++chess[currRow][k];

                for(k = currRow+1; k < n; ++k)  //updating current row rightwards
                    ++chess[k][currentColumn];

                for(k = currRow+1,j = currentColumn+1 ; k <n && j < n ; ++k,++j)    //updating right diagonal downwards
                    ++chess[k][j];

                for(k = currRow+1,j = currentColumn-1 ; k < n && j >= 0 ; ++k,--j)    //updating left diagonal downwards
                    ++chess[k][j];

                nQueen(chess,n,currRow+1);  //Claiing Recursively

                for(k = currentColumn+1 ; k < n; ++k)   //updating current column downwards
                    --chess[currRow][k];

                for(k = currRow+1; k < n; ++k)  //updating current row rightwards
                    --chess[k][currentColumn];

                for(k = currRow+1,j = currentColumn+1 ; k <n && j < n ; ++k,++j)    //updating right diagonal downwards
                    --chess[k][j];

                for(k = currRow+1,j = currentColumn-1 ; k < n && j >= 0 ; ++k,--j)    //updating left diagonal downwards
                    --chess[k][j];

                chess[currRow][currentColumn] = 0; //marking cell as "traversed but not valid"
            }//end if
        }//end for
        return;
    }//end else
}


void printSolution2(int *columnForRow, int size)
{
    int i,j;
    printf("\n\n");
    for(i = 0; i < size; ++i)
    {
        for(j=0; j < size ; ++j)
        {
            if(columnForRow[i] == j)
            printf("Q ");
            else
            printf("* ");
        }
        printf("\n");
    }
}


int checkRow(int * columnForRow ,int currentRow, int size)
{
    int diff,j;
     for(j = 0; j < currentRow ; ++j)//for each row before current row
        {
            diff = columnForRow[currentRow] - columnForRow[j];
            if( diff == 0 || diff == currentRow - j || diff == j - currentRow )//if Queen is not valid for this column, then break and check for next column for current Row.
                return 0;
        }//end for

        return 1;
}


void solveNQueen(int *columnForRow, int currentRow, int size)
{
    if(currentRow == size)
    {
        printSolution2(columnForRow,size);
        return;
    }

    int currentColumn;
    for(currentColumn = 0; currentColumn < size ; ++currentColumn)//for each column in current row
    {
        columnForRow[currentRow] = currentColumn;
        if(checkRow(columnForRow,currentRow,size))
        {
                 solveNQueen(columnForRow, currentRow+1,size);
        }
    }
    return ;
}


int **getNewChessBoard(int n)
{
     int i,j;
     int **newChessBoard   = (int **)malloc(sizeof(int *)*n);
        for(i = 0; i< n;++i)
            newChessBoard[i] = (int *)malloc(sizeof(int)*n);

        for(i = 0; i < n; ++i)
            for(j = 0; j< n; ++j)
                newChessBoard[i][j] = 0;

    return newChessBoard;
}

void freeChessBoard(int **board, int n)
{
    int i;
        for(i = 0; i < n ; ++i)
            free(board[i]);
        free(board);
return;
}

int main()
{
    int n;
    printf("Enter the value of n :");
    scanf("%d",&n);

    if(n>2)
    {
        int i,j;
        int **chess = getNewChessBoard(n);

        nQueen(chess, n, 0);

        printf("\n\nTotal Possible ways found are : %d",count);
        freeChessBoard(chess, n);
        return 0;
    }

    if(n > 2)
    {
        int *columnForRow = (int *)malloc(sizeof(int)*n);
        int i;
        for(i = 0; i < n; ++i)
            columnForRow[i] = 0;

        solveNQueen(columnForRow,0,n);

        free(columnForRow);
    }

}
