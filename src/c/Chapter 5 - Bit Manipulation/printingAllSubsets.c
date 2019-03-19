#include<stdio.h>

void printAllSubset(int size)
{
    if(size < 0)
    {printf("\nInvalid Size of Set"); return;}
    else if(size > 32)
    {printf("\nSize Too Long");return;}

    int andmask = 1,subsetBits;
    unsigned long long subset,i;
    unsigned int total_sets = 1<<size;
    printf("\n{");
    for(subset = 0; subset < total_sets; ++subset)
    {
        subsetBits=subset;
        printf("{");
        for(i = 0; subsetBits ; ++i)
        {
            if(subsetBits&(andmask<<i))
           {
               printf("%lld,",i+1);
               subsetBits = subsetBits&(subsetBits-1);             //this statement sets OFF the leftmost 1 in the bits of "subsetBits". as soon as a 1 is used, it is turned 0 so that loop exits when there are no more 1's in the left of already checked bit
           }
        }
        printf("\b}  ");    // backspace removes the trailing comma in the printed set.
    }
    printf("\nTotal Subsets = %d\n",subset);
    return;
}

int main()
{
    int n=1;
    while(1)
    {
        printf("\n\nEnter the number of elements in the set.");
        scanf("%d", &n);
        if(!n)      //0 indicates end of input.
            break;
        printAllSubset(n);
    }
    return 0;
}
