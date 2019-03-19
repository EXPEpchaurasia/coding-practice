/*Yahoo Coding Round Question August 2012*/
/* There are n stairs in a staircase. I can jump either 1,2 or 3 stairs at a time. Print how many ways are thier for me in which i can get to the top of the stairs.*/

#include<stdio.h>
#include<malloc.h>

int totalStairs;
int count = 0;

void printStairJumps(int stairsCovered,int *noOfWays, int startingIndex)
{
    if(stairsCovered == totalStairs)
    {
        int i;
        printf("\n");
        for(i = 0; i < startingIndex; ++i)
            printf("%d ",noOfWays[i]);

        count++;
    }
    else if(stairsCovered < totalStairs)
    {
        noOfWays[startingIndex] = 1;
        printStairJumps(stairsCovered+1, noOfWays ,startingIndex+1);
        noOfWays[startingIndex] = 2;
        printStairJumps(stairsCovered+2, noOfWays ,startingIndex+1);
        noOfWays[startingIndex] = 3;
        printStairJumps(stairsCovered+3, noOfWays, startingIndex+1);
    }
    return;
}

int main()
{
    printf("Number of stairs are :");
    scanf("%d",&totalStairs);
    int *noOfWays = (int *)malloc(totalStairs*sizeof(int));

    printStairJumps(0,noOfWays,0);

    printf("\n\nNumber of ways are : %d", count);
    free(noOfWays);

}
