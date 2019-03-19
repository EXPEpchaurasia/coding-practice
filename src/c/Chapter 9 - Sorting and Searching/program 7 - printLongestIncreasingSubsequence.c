#include<stdio.h>
#include<malloc.h>

#define MAX 15
int seq[] = {1,2,1,3,5 /*4*/ ,8,6,7,9,14,/* 5 */15,11,12,16,13/*6*/};

void printLongestIncreasingSubsequence()
{
    int i;
    printf("Printing Seq.\n");
    for(i = 0; i < MAX; ++i)
        printf("%d ",seq[i]);

    printf("\n");
    if(MAX < 1)
    {return;}

    int *foundTill = (int *)malloc(sizeof(int)*MAX);
    foundTill[0] = 1;
    int maxSeqLenght = 1,startingIndex = 0;
    int currentElement = 1;
    for(currentElement = 1;currentElement < MAX;++currentElement)
    {
        //printf("\nHere 1.");
        foundTill[currentElement] = 0;
        int prevElement;
        for(prevElement = currentElement - 1; prevElement >=0 ; --prevElement)
        {
            if(foundTill[prevElement] > foundTill[currentElement])
            {
                if(seq[currentElement] > seq[prevElement])
                    foundTill[currentElement] = foundTill[prevElement];
            }
        }//end for
        ++foundTill[currentElement];    //including its own value in sequence;

        if(foundTill[currentElement] >= maxSeqLenght)
        {
            maxSeqLenght = foundTill[currentElement] ;
            startingIndex = currentElement;
        }
    }

    /*
    printf("\nPrinting FoundTill.\n");
    for(i = 0 ;i < MAX;++i)
    printf("%d ",foundTill[i]);
    */

    currentElement = startingIndex -1;

    printf("\n\nMaximun Increasing Sequence is :");
    printf("%d  ",seq[startingIndex]);

    while(currentElement >= 0)
        {
            if(seq[currentElement] < seq[startingIndex] && ( foundTill[currentElement] == foundTill[startingIndex] - 1 ) )
                {
                    printf("%d  ",seq[currentElement]);
                    startingIndex = currentElement;
                    --currentElement;
                    --maxSeqLenght;
                }
            else
                    -- currentElement;
        }//end while
    return ;
}

int main()
{
    printLongestIncreasingSubsequence();
    return 0;
}
