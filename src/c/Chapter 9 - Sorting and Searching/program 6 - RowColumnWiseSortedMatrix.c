#include<stdio.h>
#define MAX 5


int searchElement(int matrix[][MAX],int row, int col, int item)
{
    int j = 0;
    col--;row--;
    while(j <= row && col >=0)
    {
        if(matrix[j][col] == item)
            return MAX*j + col;
        else
        {
            if(matrix[j][col] < item)
                ++j;
            else
                --col;
        }
    }
    return -1;
}
int main()
{
    int matrix[MAX][MAX] = {{1,10,21,30,40},{3,11,22,34,48},{9,12,25,36,60},{11,13,32,39,73},{16,17,49,80,90}};

    int i,j;
    printf("\n");
    for(i = 0 ; i < MAX; ++i)
    {
        printf("\n");
        for(j = 0; j < MAX; ++j)
        {printf(" %d ",matrix[i][j]);}
    }

    while(1)
    {
        printf("\n\nEnter the element to search :");
        scanf("%d",&j);
        if(j == 0)
            break;
        i = searchElement(matrix,MAX,MAX,j);
        if(i != -1)
        {
            printf("\nItem found at ROW %d, COLUMN %d.",i/MAX,i%MAX);
        }
        else
            printf("\nItem Not Found");
    }
}
