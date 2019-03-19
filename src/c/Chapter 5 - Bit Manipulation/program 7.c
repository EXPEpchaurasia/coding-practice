#include<stdio.h>
#include<malloc.h>


void showbits(int n)
{
    int andmask,i;
    for(i = 31;i>=0;--i)
    {
        andmask = 1<<i;
        n&andmask == 0 ? printf("0") : printf("1");
    }
}

int fetchBit(int val, int bitPos)
{
    return ((1<<bitPos) & val)==0?0:1;
}

int findMissing(int *arr, int size)
{
    int isOdd = 0;
    isOdd = size%2;
    int missing=0,i,j,onesCount;
    int reqOnes = (size+isOdd)>>1;
    for(i=0;i<sizeof(int)*8;++i)
    {
        onesCount = 0;
        for(j=0;j<size;++j)
        {
            if(fetchBit(arr[j],i))
            ++onesCount;
        }
        //printf("\nOnes count for BIT %d is :%d",i,onesCount);


        int k = ( ( size + isOdd ) / (1 << ( i + 1 ) ) );
        int mod = ( ( size + isOdd ) % (1 << ( i + 1 ) ) );
        if(k==0)
        {
            reqOnes = size - (1 << i ) + 1;
            //printf("\nAnd mask at last is : %d",andmask);
        }
        else
            reqOnes = (k * (1 << i)) + ((mod > (1 << i)?(mod - (1<< i)):0));

        printf("\nAt  BIT %d   Ones found : %d\t\t Ones Required :%d",i,onesCount,reqOnes);
        if(onesCount < reqOnes)
            missing |= (1<<i);

        if(k==0)
            break;
    }
    return missing;
}


int main()
{
    int *arr ,n,missingValue;
    while(1)
    {
            printf("\n\nEnter the size of array :");
            scanf("%d",&n);

            if(n==-1)
            break;

            printf("Enter the missing value :");
            scanf("%d",&missingValue);
            while(missingValue > n | missingValue < 0)
            {
                printf("\nWrong value. Enter again :");
                scanf("%d",&missingValue);
            }
            int i,j;
            arr = (int *)malloc(n*sizeof(int));
            for(i=0,j=0;i<n;i++,++j)
            {
                if(j!=missingValue)
                {
                    arr[i] = j;
                }
                else
                    arr[i] = ++j;
            }

            printf("\nMISSING VALUE IS : %d",findMissing(arr,n));
            free(arr);
    }
    return 0;
}
