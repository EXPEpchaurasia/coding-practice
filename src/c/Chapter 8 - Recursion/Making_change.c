#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int main()
{
      printf("Enter the number of coins :");
      int i,n;
      scanf("%d",&n);
      if(n<1)
        {printf("\n Processing not possible.");getch();return;}
      int *arr = (int *)malloc(n*sizeof(int));
      int temp = 0;

        printf("\nEnter the value of coins :");

        for(i=0;i<n;i++)
        {
                scanf("%d",arr+i);
                if(*(arr+i)<=temp)
                {
                    printf("\nGiven input should be in STRICTLY INCREASING ORDER.");
                    getch();
                    return;
                }
                temp = *(arr+i);
        }

        for(i=0;i<n;i++)
               printf("%d ",*(arr+i));
        printf("\n\n");
        int amount;
        printf("Enter your amount for Denomination\n");
        scanf("%d", &amount);

        if(!(findDenomination(arr,n-1,amount)) )
        {
                printf("\nDenomination not possible.");
        }

        /*write your code before this point*/
        free(arr);
        //getch();
        return ;
}

int findDenomination(int *arr, int n, int amt)
{
        if((n<0))
        {
            if(amt != 0)
                return 0;
            else
                return 1;
        }


        if(*(arr+n) == amt)
        {
            printf("Denomination is %d ",*(arr+n));
            return 1;
        }
        else if(amt > *(arr+n))
        {
                while(n>=0)
                {
                        if(findDenomination(arr, n-1,amt - *(arr+n)))
                        {
                                printf("%d ",*(arr+n));
                                return 1;
                        }
                        n--;
                }
                return 0;
        }
        else
            return findDenomination(arr, n-1,amt);
}
