#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define MAX 8

char letters[MAX] = {'a','b','c','d','e','f','g','h'};
char LETTERS[MAX] = {'A','B','C','D','E','F','G','H'};
int count = 0;

int main()
{
       int length;
       printf("Enter the length of password :");
       scanf("%d",&length);
       if(length > MAX)
       {
                printf("\nNo Well Ordered password Possible.");
                getch();
                return;
       }
       char *str  = (char *)malloc(length*sizeof(char));
       int i = 0;

       while(i<length)
            *(str +i++) = '\0';

       print_seq(MAX-length,0,MAX,str,1);
       printf("\nCount = %d",count);
       free(str);
       getch();
}

print_seq(int limit, int startPos, int n, char *seq, int charNum)
{
           int i;
           if(startPos > limit)
                return;
           else if(limit == (n-1))
           {
                i = startPos;
                while(i<=limit)
                {
                      printf("%s%c\n",seq,letters[i]);
                      printf("%s%c\n",seq,LETTERS[i++]);
                      count+=2;
                }
                return;
           }
           else
           {
                while(startPos<=limit)
                {
                     *(seq+charNum-1)=letters[startPos];
                     print_seq(limit+1,startPos+1,n,seq,charNum+1);
                     *(seq+charNum-1)=LETTERS[startPos];
                     print_seq(limit+1,startPos+1,n,seq,charNum+1);

                     startPos++;
                }
                *(seq+charNum) = '\0';
                return;
           }
}
