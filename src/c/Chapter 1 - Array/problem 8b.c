#include<stdio.h>
#include<string.h>

int isSubstring(char *s1, char *s2)
{

    if(s1==NULL || s2 == NULL)
        return 0;
    int i,j=0;
    while(1)
    {
        for(i=0;*(s1+i) == *(s2+j);++i,++j);
        if(*(s1+i)=='\0')
            return 1;
        else if(*(s2+j)=='\0')
            return 0;
        else
            j= j-i+1;
    }
}


int main()
{

    char str1[20],str2[20],strconcat[50];
    strconcat[0] = '\0';
    printf("Enter string 1 :");
    scanf("%s",str1);
    printf("\n\nEnter string 2 :");
    scanf("%s",str2);

    if(strlen(str1) != strlen(str2))
    {printf("\nNot Rotated.");return 0;}

    strcat(strconcat,str1);
    strcat(strconcat,str1);

    printf("\nConcatenated is : %s",strconcat);
    if(isSubstring(str1,strconcat))
    printf("\nYES Rotated.");
    else
    printf("\nNot Rotated.");

    return 0;
}
