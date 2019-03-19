#include<stdio.h>
#include<string.h>
//Program to remove duplicate characers from a given string


int main()
{
    int len , i , j,nextindex;
    char str[50];
    printf("Enter the string to check :");
    scanf("%s",str);

    len = strlen(str);
    for(i = 0 ; i < len ; ++i)
    {
        if(str[i] != '$')
        for(j=i+1 ; j < len ; ++j)
        {
            if(str[j] != '$')
                if(str[j] == str[i])
                    str[j] = '$';

        }
    }

    printf("\n new string is :%s", str);

    i=0;j=i+1;
    while(j<len && i<len-1)
    {
        if(str[i] == '$')
        {
            for(j = i+1; j < len ; ++j)
            {
                if(str[j] != '$')
                {
                    str[i] = str[j];
                    str[j] = '$';
                    ++j;
                    nextindex = i+1;
                    break;
                }
            }
        }
        ++i;
    }
    str[nextindex] = '\0';
    printf("String with removed : %s",str);
}
