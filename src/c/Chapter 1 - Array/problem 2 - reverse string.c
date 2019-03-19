#include<stdio.h>
#include<string.h>

int main()
{
    int len, lim, i;
    char str[30], temp;
    printf("Enter the string to reverse : ");
    scanf("%s", str);

    len = strlen(str);
    lim = len/2;

    for(i = 0 ; i < lim ; ++i)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    for(i = 0; i < lim ; ++i)
    {
        if(str[i] != str[len - i - 1])
        {printf("\nNOT PALINDROME");break;}
    }
    if(i == lim)
    {printf("\nPALINDROME");}

    printf("\n\nReversed string is : %s", str);

    return 0;
}
