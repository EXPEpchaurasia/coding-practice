#include<stdio.h>
#include<malloc.h>

typedef struct HEAP Heap;
struct HEAP
{
    int *root;
    unsigned int size;
};

Heap * getHeap()
{
    Heap *newHeap = (Heap *)malloc(sizeof(Heap));
    newHeap->root = NULL;
    newHeap->size = 0;
    return newHeap;
}

void printHeap(Heap *heap)
{
    int size = heap->size;

    printf("\n\nHeap is :");
    if( size == 0 )
        {
            printf(" Empty");
            return;
        }

    int startIndex = 1,j,limit;
    printf("\n");
    while(size)
    {
        limit = startIndex;

        if(size < startIndex)
            limit = size;
        for(j = 0; j < limit ; ++j )
            printf("%d  ",(heap->root)[startIndex+j-1]);
        printf("\n");

        size -= limit;
        startIndex <<= 1;
    }

}

void buildMinHeap(Heap *heap, int *array, int size)
{
    if( !array || size < 0)
        return;

    if(size == 0)
    {
        heap->root = array;
        return;
    }

    int i;
    heap->root = array;
    for(i = 1; i <= size; ++i)
    {
            (heap->size)++
            heapify(h);
    }
    return ;
}

void heapify(Heap *h)
{

    printf("here 1.");
    int currentIndex = h->size - 1;
    int parent;
    while(currentIndex)
    {
        parent = (currentIndex - 1)/2;
        if((h->root)[currentIndex] > (h->root)[parent] )
            break;

        (h->root)[currentIndex] = (h->root)[currentIndex] ^ (h->root)[parent];
        (h->root)[parent] = (h->root)[currentIndex] ^ (h->root)[parent];
        (h->root)[currentIndex] = (h->root)[currentIndex] ^ (h->root)[parent];

        currentIndex = parent;
    }
}

int insertInMinHeap(Heap *h, int item)
{
    ++(h->size);
    (h->root)[h->size - 1] = item;
    heapify(h);
}

int main()
{
    FILE *inputFile = fopen("HeapData.txt","r");
    if(!inputFile)
    {
        printf("Error file opening !!!");
        exit(1);
    }
    int n,i;
    fscanf(inputFile,"%d",&n);
    int *array = NULL;
    if(n > 0)
    {
        array = (int *)malloc(sizeof(int) * (n+20));
        for(i = 0 ; i < n ; ++i)
            fscanf(inputFile,"%d",&array[i]);
        printf("\nArray is : ");
        for(i = 0; i < n; ++i)
            printf("%d ",array[i]);
        Heap *h = getHeap();
        buildMinHeap(h,array, n);

        printHeap(h);

        printf("\nHow many elements to add in heap :");
        scanf("%d",&n);
        int item;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &item);
            insertInMinHeap(h, item);
        }
        printHeap(h);

        printf("\nArray is : ");
        for(i = 0; i < n; ++i)
            printf("%d ",array[i]);
    }
    return 0;
}
