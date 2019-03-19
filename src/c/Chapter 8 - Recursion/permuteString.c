#include<stdio.h>
#include<string.h>
#define MAX 20

void permute(char *string, int startIndex, int endIndex, int N)
{
    if(startIndex == endIndex)
    {
        printf("%s\n", string);
        return;
    }
    else
    {
        int currentStart = startIndex;
        char temp;
        for(;currentStart < endIndex; ++currentStart)
        {
            temp = string[currentStart];
            string[currentStart] = string[endIndex-1];
            string[endIndex-1] = temp;

            permute(string, startIndex, endIndex-1, N);

            temp = string[currentStart];
            string[currentStart] = string[endIndex-1];
            string[endIndex-1] = temp;
        }
    }
    return;
}

int main()
{
        char string[MAX];
        printf("Enter the String : ");
        scanf("%s", string);

        permute(string, 0,strlen(string), strlen(string));
}
