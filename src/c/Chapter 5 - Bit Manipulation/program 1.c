#include<stdio.h>

void showbits ( int n )
{
    int i, k, andmask ;
    int size = sizeof(int) * 8;
    for ( i = size-1 ; i >= 0 ; --i)
    {
        andmask = 1 << i ;
        k = n & andmask ;
        k == 0 ? printf ( "0" ) : printf ( "1" ) ;
     }
}

int setBits(int n, int m, int i, int j)
{
    if(i>j)
    {
        printf("\nWrong values.");
        return 0;
    }
    printf("\nBinary of N is :");showbits(n);
    printf("\nBinary of M is :");showbits(m);
    int andmask = ~0;
    andmask = andmask ^ ((1<<(j+1))-1);
    andmask = andmask | ((1<<i)-1);
    //printf("\nAndmask is :    ");showbits(andmask);
    n = n&andmask;
    n=n|(m<<i);
    return n;
}

int main()
{
    int i,n,m,j;
    printf("Enter value of N :");
    scanf("%d",&n);
    printf("\nEnter value of M :");
    scanf("%d",&m);
    printf("Enter i and j values.");
    scanf("%d %d",&i,&j);
    n=setBits(n,m,i,j);
    printf("\nNew val of N is:");
    showbits(n);
}

int dummy()
{
    int j = -8,k=524288,i=4;

    while(i--)
    {
        printf("Binary of %d is : ",j);
        showbits(j);
        printf("\n");
        j=j>>1;
    }
    i=15;
    printf("\n");
    int flag = 1;
    while(i--)
    {
        if(k<0)
        flag = 0;
        printf("Binary of %d is : ",k);
        showbits(k);
    }
}

