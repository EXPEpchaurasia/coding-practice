#include<stdio.h>
//Rotating an image stored in NxN matrix to 90 degrees.s
int main()
{
   // int a[5][5] = {{1,0,0,0,0},{1,1,0,0,0},{1,1,1,0,0},{1,1,1,1,0},{1,1,1,1,1}};
   int a[2][2] = {{1,0},{1,1}};
    int N = 2,i,j,temp;

    printf("Initial image is : \n")
    for(i = 0; i< N ; ++i)
    {
         for( j = 0  ; j < N ; ++j )
         {
            printf("%d ",a[i][j]);
         }
         printf("\n");
     }

for(i = 0 ; i < (N/2) ; ++i)
{
    for(j = i ; j < N-1-i ; ++j)
    {
        temp = a[i][j];
        a[i][j] = a[N-1-j][i];
        a[N-1-j][i] = a[N-1-i][N-1-j];
        a[N-1-i][N-1-j] = a[j][N-1-i];
        a[j][N-1-i] = temp;
    }
}

printf("\n\nRotated image is :\n");
for(i = 0; i< N ; ++i)
    {
         for( j = 0  ; j < N ; ++j )
         {
            printf("%d ",a[i][j]);
         }
         printf("\n");
     }

    return 0;

}
