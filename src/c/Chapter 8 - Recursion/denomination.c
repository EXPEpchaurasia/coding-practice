#include<stdio.h>
#include<conio.h>
 
 int main()
 {
           int n,i;
     printf("Enter the amount:");
     scanf("%d",&n);
     i=n;
     printf("\n25 x %d",n/25);
     n=n%25;
     printf("\n10 x %d",n/10);
     n=n%10;
     printf("\n1 x %d\n",n);
     n=i;
     for(i = 1;i<=n/25;i++)
     {
           printf("25 ");      
     }
     printf("\n");
     n=n%25;
     for(i = 1;i<=n/10;i++)
     {
           printf("10 ");      
     }
     n= n%10;
     printf("\n");
     for(i = 1;i<=n/1;i++)
     {
           printf("1 ");      
     }
     
     getch();                     
 }
