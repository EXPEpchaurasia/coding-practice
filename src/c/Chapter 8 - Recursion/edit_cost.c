#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

int min(int, int, int);
int editDistance(char *, char *);
int editDistMemoization(char *, char *);
int main()
{
        char arr[20],brr[20];
        printf("Enter the source string:");
        gets(arr);
        printf("Enter the target string:");
        gets(brr);

        printf("\nSTR 1 :%s :LENGTH :%d\n",arr,strlen(arr));
        printf("STR 2 :%s :LENGTH :%d",brr,strlen(brr));

        printf("\n The minimum edit Distance is :%d",editDistance(arr,brr));

        editDistMemoization(arr, brr);
        getch();
        return 0;
}

int editDistMemoization(char *str1, char *str2)
{
        int i;
        int**arr = (int **)malloc(strlen(str1+1)*sizeof(int *));
        for(i = 0;i<strlen(str1)+1; i++)
                arr[i] = (int*)malloc(sizeof(int)*(strlen(str2)+1));

        arr[0][0]=0;

        int j =strlen(str2);
        for(i = 1;i<=j;i++)
                arr[0][i] = i;

        j= strlen(str1);
        for(i = 1;i<=j;i++)
                arr[i][0] = i;

        for(i=1;i<=strlen(str1);i++)
        {
                for(j=1;j<=strlen(str2);j++)
                {
                        if(*(str1+i-1) == *(str2+j-1))
                           arr[i][j] = min(arr[i-1][j] +1, arr[i][j-1] +1, arr[i-1][j-1]);
                        else
                            arr[i][j] = min(arr[i-1][j] +1, arr[i][j-1] +1, arr[i-1][j-1] + 2);
                }
        }

        printf("\n");

         for(i=0;i<=strlen(str1);i++)
        {
                for(j=0;j<=strlen(str2);j++)
                        printf( "%d ", arr[i][j]);

                printf("\n");
        }


        printf("\n Through Memoization : %d", arr[i-1][j-1]);
        j=strlen(str1)+1;
        for(i = 0;i<j; i++)
                free(arr[i]);
    //    printf("\n1. Here");
        free(arr);

        return 0;
}

int editDistance(char *str1, char *str2)
{
        if(strlen(str1) == 0)
                return strlen(str2);
        else if(strlen(str2) == 0)
                return strlen(str1);
        else if(*str1 == * str2)
                return min(editDistance(str1+1,str2) + 2, editDistance(str1,str2+1) + 2, editDistance(str1+1, str2+1));
        else
                return min(editDistance(str1+1,str2) + 2, editDistance(str1,str2+1) + 2, editDistance(str1+1, str2+1)+3);
}

int min(int a, int b, int c)
{
        if(a<=b)
        {
            if(a<=c)
                return a;
            else if(c<=b)
                return c;
        }
        else
        {
             if(b<=c)
                return b;
             else
                return c;
        }
}
