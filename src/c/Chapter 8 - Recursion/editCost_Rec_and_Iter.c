#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define insertCost 1
#define deleteCost 1
#define replaceCost 2

int min(int a, int b, int c)
{
   return  ((a > b )?(( b > c )? c : b ):((a > c )? c : a));
}

int editCostRecursive(char *source,char *dest)
{
    if( !(*source) )    //if source string is at end
        return strlen(dest)*insertCost;
    else if( !(*dest) ) //if dest string is at end
        return strlen(source)*deleteCost;
    else
    {
        if(*source == *dest)        //current character of both the strings is same, then do not use replacement cost
            return min(editCostRecursive(source+1,dest+1), editCostRecursive(source, dest +1) + insertCost, editCostRecursive(source + 1, dest) + deleteCost);
        else
            return min(editCostRecursive(source+1,dest+1) + replaceCost, editCostRecursive(source, dest +1) + insertCost, editCostRecursive(source + 1, dest) + deleteCost);
    }
}

int editCostIterative(char * source, char * dest)
{
    if( ! (*source) )
        return strlen(dest)*insertCost;
    else if( ! (*dest) )
        return strlen(source)*deleteCost;

    int i,j,sourceLen = strlen(source),destLen = strlen(dest);
    int **costMatrix = (int **)malloc((sourceLen+1)*sizeof(int*));
    for(i = 0; i < sourceLen+1; ++i)
        costMatrix[i] = (int *)malloc((destLen+1)*sizeof(int));

    costMatrix[0][0] = 0;

    for(i = 1; i <= destLen ; ++i)
        costMatrix[0][i] = i*deleteCost;

    for(i = 1; i <= sourceLen ; ++i)
        costMatrix[i][0] = i*insertCost;

    for(i = 1; i < sourceLen + 1; ++i)
    {
        for(j = 1; j < destLen + 1; ++j)
        {
            if(*(source+i-1) == *(dest+j-1))
                costMatrix[i][j] = min(costMatrix[i-1][j] + deleteCost , costMatrix[i][j-1] + insertCost, costMatrix[i-1][j-1]);
            else
                costMatrix[i][j] = min(costMatrix[i-1][j] + deleteCost , costMatrix[i][j-1] + insertCost, costMatrix[i-1][j-1] + replaceCost);
        }
    }

    j = costMatrix[sourceLen][destLen];

    for(i = 0 ; i < sourceLen+1; ++i)
        free(costMatrix[i]);
    free(costMatrix);

    return j;
}

int main()
{
    char source[20],dest[20];

    printf("Enter the source string :");
    gets(source);
    printf("\nEnter the dest string :");
    gets(dest);
    printf("\nSource = %s, dest = %s, min = %d", source,dest,min(1,2,3));
    printf("\nMinimum Edit Cost... Recurseive :%d.   Iterative : %d",editCostRecursive(source,dest),editCostIterative(source,dest));
    getch();
    return 0;
}
