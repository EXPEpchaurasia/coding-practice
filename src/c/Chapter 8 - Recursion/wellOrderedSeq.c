#include<stdio.h>
#include<malloc.h>

#define MAX 8

char letter[MAX] = {'a','b','c','d','e','f','g','h'};
char LETTER[MAX] = {'A','B','C','D','E','F','G','H'};
int count = 0;


void printSeq(char *seq, int startPos ,int limit, int n,int currLength)
{
    int i,currCharacter;
    if(currLength == n-1)
    {
        for(currCharacter = startPos; currCharacter<=limit;++currCharacter)
        {
            printf("\n%s%c",seq,letter[currCharacter]);
            printf("\n%s%c",seq,LETTER[currCharacter]);
            count +=2;
        }
        return ;
    }
    for(currCharacter=startPos;currCharacter<=limit;++currCharacter)
    {
        seq[currLength] = letter[currCharacter];
        printSeq(seq,currCharacter+1,limit+1,n,currLength+1);
        seq[currLength] = LETTER[currCharacter];
        printSeq(seq,currCharacter+1,limit+1,n,currLength+1);
    }
    seq[startPos] = '\0';
    return;
}


int main()
{
    int n;
    printf("How Many characters :");
    scanf("%d",&n);

    if(n > MAX | n<=0)
    {
        printf("NOT POSSIBLE .");
        return;
    }
    else
    {
        char *seq = (char *)malloc((n+1)*sizeof(char));
        int i = 0;
        for(;i<=n;)
            {seq[i++] = '\0';}

        printSeq(seq,0,MAX-n,n,0);
//        printf("\nNumber of strings printed  = %d",count);
        free(seq);
    }
getch();
}
