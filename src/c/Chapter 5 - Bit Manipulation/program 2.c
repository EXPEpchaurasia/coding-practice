#include<stdio.h>

void showbits(int n)
{
    int intsize_bits = sizeof(n)*8;
    int andmask,i,k;
    for(i = intsize_bits-1 ; i>=0;--i)
    {
        andmask = 1<<i;
        ((n&andmask) == 0)?printf("0"):printf("1");
    }
}


void printDecimalBinary(int value)
{
    float dec = value/1.0;
    printf("%f ",dec);
    while(dec>1)
    dec = dec/10.0;
    printf("\n%f \n",dec);
   int  n=20;
    while(n--)
    {
        dec = dec*2.0;
        dec>=1?({printf("1");dec-=1.0;}):printf("0");

        printf("--%2f--\n",dec);
    }
}

int main()
{
    int d;
    scanf("%d",&d);
    printDecimalBinary(d);
    return 0;
}
