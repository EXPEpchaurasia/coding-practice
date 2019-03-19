#include<stdio.h>
#include<malloc.h>
int count = 0;
int curr = 0;
int *currencies = NULL;
int *currencyDenom = NULL;

void calculateDenominations(int *currency, int denomination, int denomIndex)
{
    if(denomination == 0)
    {
            int i;
            ++count;
            printf("\n");
            for(i = 0; i < curr;++i)
                printf(" %d x %d ",currencies[i],currencyDenom[i]);
            return;
    }
    else if(*currency == 0)
        return;
    else
    {
        int n,currentTotal;
        for(n = 0;n<= denomination/(*currency) ; ++n)//for all denominations possible for this currency, calculate denominations
        {
            currentTotal = n*(*currency);
            if(currentTotal <= denomination)
            {
                currencyDenom[denomIndex] = n;
                calculateDenominations(currency+1,denomination - currentTotal,denomIndex+1);
                currencyDenom[denomIndex] = 0;
            }
            else
                return;
        }
    }
    return ;
}


int main()
{
    printf("\n**********Calculate number of ways for CURRENCY DENIMINATION********\n\n\n");
    int n,denomination;
    printf("Enter the denominatipon Value :");
    scanf("%d",&denomination);
    if(denomination <=0)
    return 1;
    printf("\nHow many currencies are their :");
    scanf("%d",&n);
    if(n>0)
    {
        int *currency = (int *)malloc((n+1)*sizeof(int));
        currencies = currency;
        currencyDenom = (int *)malloc(n*sizeof(int));
        curr = n;
        int i,value;
        for(i = 0; i<n;)
        {
            while(1)
            {
                    printf("\nEnter the currency number %d (in rupees): ",i+1);
                    scanf("%d",&value);
                    if(value>0)
                    {
                        currency[i++] = value;
                        break;
                    }
                    else
                    printf("Invalid Entry.");
            }
        }
        currency[i] = 0;

        calculateDenominations(currency,denomination,0);
        printf("\n\n\nPossible ways are : %d",count);
        free(currency);
    }
    return 0;
}
