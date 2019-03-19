#include<stdio.h>
#include<string.h>

int main()
{

    printf("ASSUMPTIONS : 1. Only lowercase english language alphabets without spaces are provided as input of length less than 20\n");
    int i,len;
    char str [20];
    int occured[26];

    for(i = 0; i < 26 ; ++i)
    {
        occured[i] = 0;
    }

   // printf("%d\n",'a');

    printf("Enter the string to check :");
    scanf("%s",str);
   // printf("\n String is : %s",str);
    len = strlen(str);

    for(i = 0 ; i < len ; ++i)
    {
        if(occured[str[i] - 97] == 1)
        {
                printf("\nDuplicate exists.");
                break;
        }
        else
                occured[str[i]-97] =  1;

    }
    if(i==len)
    printf("\nNo duplicate exists. :)");

    for(i = 0 ; i< 26; ++i)
    printf("\n%c %d",97+i,occured[i]);
}
