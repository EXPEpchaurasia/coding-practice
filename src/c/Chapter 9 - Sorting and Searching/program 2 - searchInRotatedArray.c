#include<stdio.h>
#include<malloc.h>

#define MAX 10

int array[MAX] = {17,20,23,25,34,45,49,51,51,4};

int searchInRotatedRecursively(int start,int end,int key)
{
    while(start <= end)
    {
        int mid = (start + end +1)/2;
        if(array[mid] == key)
            return mid;

        printf("\nStart = %d, end = %d, mid = %d",start,end,mid);

        if(array[start] < array[end])
        {
            if(array[mid] < key )
                start = mid+1;
            else
                end = mid -1;
        }
        else if(array[mid] > array[start])
        {
            if(key >= array[start] && key < array[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if(key < array[mid] || key >= array[start])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int searchInRotated(int start, int end, int key)
{

    if(start > end)
        return -1;
    int mid = (start + end + 1)/2;

    printf("\nStart = %d, end = %d, mid = %d",start,end,mid);

    if( array[mid] == key)
        return mid;

    if(array[end] > array[start])
    {
        if(array[mid] > key)
            return searchInRotated(start,mid-1,key);
        else
            return searchInRotated(mid+1,end,key);
    }
    else if(array[mid] >= array[start])
    {
        if(key < array[mid] && key >= array[start])
            return searchInRotated(start,mid-1,key);
        else
            return searchInRotated(mid+1,end,key);
    }
    else if(key >= array[start] || key < array[mid])
        return searchInRotated(start,mid-1,key);
    else
        searchInRotated(mid+1,end,key);
}

int main()
{
    int i;
    for(i = 0; i < MAX ; ++i)
        printf("%d(%d)   ",array[i],i);
    int key;
        while(1)
        {
            printf("\n\nEnter the element to search :");
            scanf("%d",&key);
            if(!key)
                break;

            printf("\nSearching...");
            //key = searchInRotated(0,MAX-1,key);
            key = searchInRotatedRecursively(0,MAX-1,key);
            if(key != -1)
                printf("\nElement FOUND....!!!! Its Index is %d",key);
            else
                printf("\n\nElement Not Found");
        }

    return ;
}
