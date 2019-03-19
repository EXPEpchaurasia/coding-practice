#include<stdio.h>
#include<malloc.h>

void freeArray(int **arr, int n)
{
    int i = 0;
    while(i<n)
        free(arr[i++]);
    free(arr);
}

int main()
{
    int n,i,j;
    printf("eNTER THE VALUE OF n :");
    scanf("%d",&n);
    if(n<=0)
    {printf("\nNo of ways =0");return 0;}

    int **arr = (int **)malloc(n*sizeof(int*));
    for(i = 0; i < n ; ++i)
        arr[i] = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            arr[i][j] = 1;

    int cross,crossX,crossY;
    printf("How many cross points are there.");
    scanf("%d",&cross);

    for(i=0;i<cross;++i)
    {
        printf("Enter the cross point number %d :",i+1);
        scanf("%d %d",&crossX,&crossY);
        if(!(crossX < 0 || crossX > n-1 || crossY < 0 || crossY > n-1))//if cross point is inside the board.
            arr[crossX][crossY] = 0;
    }

    if(arr[0][0] == 0) //starting point is Blocked, hence no path possible
    {
        printf("No of path =  0");
        freeArray(arr,n);
        return 0;
    }

    for(i=1;i<n;++i)
    {
        for(j=1;j<n;++j)
            arr[i][j] = arr[i][j]*(arr[i-1][j] + arr[i][j-1]);
    }

/*
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
*/


    printf("\nNumber of ways are %d",arr[n-1][n-1]);
    freeArray(arr,n);
    return 0;

}
