#include<stdio.h>
#include<malloc.h>

void printPar(char *combination, int openedSoFar, int closedSoFar, int n)
{
    if(openedSoFar >n || closedSoFar > openedSoFar)
        return;
    else if(closedSoFar == n)
        printf("%s, ",combination);
    else
    {
        combination[openedSoFar + closedSoFar] = '(';
        printPar(combination, openedSoFar+1, closedSoFar, n);
        combination[openedSoFar + closedSoFar] = ')';
        printPar(combination, openedSoFar, closedSoFar+1, n);
    }
    return;
}

int main()
{
    int n;
    printf("*******PRINT N-Pairs of Parenthesis's valid combination. ********\n\n");
    printf("Enter the number :");
    scanf("%d",&n);

    if(n>0)
    {
        char *combination = (char *)malloc((n<<1)*sizeof(char) +1);
        combination[(n<<1)] = '\0';
        printPar(combination, 0,0,n);
        //free(combination);
    }
    return 0;
}
