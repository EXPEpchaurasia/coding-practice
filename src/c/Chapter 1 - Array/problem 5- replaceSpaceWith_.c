#include<stdio.h>

int main()
{
    char str[100];
    printf("Enter the Sentence : ");
    gets(str);
    printf("\n\nThe string is : ");
    puts(str);

    int i,count;
    for(i = 0,count = 0 ; str[i] != '\0' ; ++i)
    {
        if(str[i] == ' ')
        ++count;
    }
    printf("\n No. od spaces are : %d", count);

    while(i >=0)
    {
        if(str[i] != ' ')
        {
            str[i+ (count*2)] = str[i];
        }
        else
        {
            str[i+(count*2)] = '0';
            str[i+(count*2)-1] = '2';
            str[i+(count*2)-2] = '%';
            --count;
        }
        --i;
    }
printf("\n\nmodified string is :");
puts(str);

return 0;
}
