#include<stdio.h>
#include<malloc.h>

#define MAX 100000

int getInt()
{
    char ch;
    int number = 0;
    ch = getchar();
    while(ch < 48 || ch >57)
    {
            ch = getchar();
    }
    while(ch > 47 && ch < 58)
    {
        number = (number*10) + ch-48;
        ch = getchar();
    }
    return number;
}

unsigned int getUniqueElements(unsigned int n)
{
    int i=0,element,unique=0;
    int charSize = sizeof(char);
    char andmask = 1;
    unsigned int tableSize = (MAX/charSize)+1;

    char *hashTable = (char*)malloc(tableSize);

    //initializing the table to 0 for all elements
    while(tableSize--)
        hashTable[tableSize]='\0';

    FILE *fptr = fopen("tripletInput.txt","r");
    for(i = 0; i < n; ++i)
    {
            fscanf(fptr,"%d",&element);
            if(!( (hashTable[ element/charSize ]) & (andmask<<(element%charSize)) )  )          //checking the bit number "element" value. If Already SET, then ignore element otherwise turn it ON
            {
                hashTable[ element/charSize ] |= (andmask<<(element%charSize));             //Turn that bit ON.
                ++unique;
            }
    }
    return unique;
}

int numOfTriplet()
{
    printf("\nHow many elements are there :");
    int n = getInt();
    if(n < 3)
        return 0;
    else
        printf("\nScanning elements from input file...");

    n = getUniqueElements(n);
    printf("\nNumber of distinct elements are : %u",n);

    if(n < 3)
        return 0;
    else
    {
        int triplets = 0;
        n= n-2;
        int currentSum = (n*(n+1))>>1;      //calculates sum of first n natural numbers
        while(n)
        {
            triplets += currentSum;
            currentSum -=n;
            --n;
        }
        return triplets;
    }
}

int main()
{
    printf("\n\nNumber of Triplets Possible are :%d ",numOfTriplet());
    return 0;
}
