#include<stdio.h>
#include<malloc.h>

int arraySize = 0;

void printArray(int *array, int size)
{
    int i = 0;
    printf("\n");
    while(i < size)
        printf("%d ",array[i++]);
    return;
}

void insertionSort(int *arr, int size)
{
    int i,j,key;
    for(i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;
        while(arr[j] > key && j >= 0)
            arr[j+1] = arr[j--];

        arr[j+1] = key;
    }
    return ;
}

void bubbleSort(int *arr, int size)
{
    int i,j;
    for(i = 0 ; i < size-1 ; ++i)
    {
        for(j= 1 ; j < size - i ; ++j)
        {
            if(arr[j-1] > arr[j])
            {
                arr[j-1] = arr[j-1] + arr[j];
                arr[j] = arr[j-1] - arr[j];
                arr[j-1] = arr[j-1] - arr[j];
            }//end if
        }//end for
    }//end for
}

void selectionSort(int *arr, int size)
{
    int i,j,key, keyIndex;;
    for(i = 0; i < size-1 ; i++)
    {
        key = arr[i];
        keyIndex = i;
        for(j = i+1; j < size; ++j)
            if(arr[j] < key)
                {
                    keyIndex = j;
                    key = arr[j];
                }
        if(keyIndex != i)
        {
            for(j = keyIndex ; j > i; --j)
                arr[j] = arr[j-1];
            arr[j] = key;
        }
        //printArray(arr,size); //prints the result of every pass
    }
    return;
}

void quickSort(int *arr,int start, int end)
{
    if(start >= end)
    return;
    int pivot = start;
    int lptr = start+1;
    int rptr = end;

    //printf("\n Pivot = %d, start = %d, End = %d ",arr[pivot],arr[lptr], arr[end]);

    int temp;
    while(lptr < rptr)
    {
        if(arr[lptr] > arr[rptr])
        {
             temp = arr[lptr];
             arr[lptr] = arr[rptr];
             arr[rptr] = temp;
        }
        if(arr[lptr] <= arr[pivot])
            ++lptr;
        if(arr[rptr]>= arr[pivot])
            rptr--;
    }

    if(arr[rptr] < arr[pivot])
    {
        temp = arr[pivot];
        arr[pivot] = arr[rptr];
        arr[rptr] = temp;
    }

    //printArray(arr,arraySize);
    quickSort(arr, pivot, rptr-1);
    quickSort(arr, rptr+1,end);

}

int main()
{
    int n;
    printf("Enter N :");
    scanf("%d",&n);
    arraySize = n;

    if(n>1)
    {
        int *arr = (int *)malloc(n*sizeof(int)),i;
        if(arr)
        {
            printf("Enter elements :");
            for(i = 0; i < n; ++i)
                scanf("%d",&arr[i]);

            //insertionSort(arr,n);
            //bubbleSort(arr,n);
            //selectionSort(arr,n);
            quickSort(arr,0,n-1);
            printArray(arr,n);
            free(arr);
        }//end if
    }//end if
}
