#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int main()
{
    int i,j,max=0, maxIndex=0, currMax=0, n;
    printf("How many elements are there in the Array :");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    int *brr = (int *)malloc(n*sizeof(int));

    printf("\nEnter the elements(integers only):");

    for(i=0;i<n;i++)
    {scanf("%d",arr+i);}


    max = arr[0];
    for(i = 0; i < n; i++)
    {
          currMax = brr[i] = arr[i];

          for(j = i+1; j < n; j++)
          {
                brr[j] = brr[j-1] + arr[j];
                if(brr[j] >  currMax)
                {
                          currMax = brr[j];
                }
          }

          brr[i] = currMax;
          if(currMax > max)
          {
               max = currMax ;
               maxIndex = i;
          }
    }
    printf("\n\nMax sum is :%d\n", max);
    printf("Max index is :%d\n\n", maxIndex);
    i = maxIndex;
    int sum = 0;
    while((sum != max) && (i<n))
    {
         sum = sum+arr[i];
         printf(" %d", arr[i++]);
    }

    printf("\n\nThe max Array was :");
    for(i=0;i<n;++i)
    printf(" %d",*(brr+i));

    getch();
    free(arr);free(brr);

}
