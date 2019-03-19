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
    char s1[20],s2[20];
    int i,j,n;
    scanf("%s %s",s1,s2);

    if((n=strlen(s1))!=strlen(s2))
        {printf("NOT ROTATION");return 0;}

    if(!(strcmp(s1,s2)))
        {
            printf("Yes ROTATION.");return 0;
        }

    for(j=0;j<n;++j)
    {
        if((s1[n-1] == s2[j]) && (s1[0]== s2[(j+1)%n]))     //if probable split point is found
        {
            printf("\nprobable split point is : %d",j+1);
            for(i = 1; s2[(j+i)] != '\0' ; ++i)
            {
                if(s1[i-1] != s2[(j+i)%n])
                {break;}
            }
            if(s2[j+i] == '\0')
            {
                if(isSubstring((s1+(i%n)),s2))
                    printf("\nYes Rotation.");
                else
                    printf("\nNot Rotation.");
                return 0;
            }

        }
    }
    printf("\nNo Rotation.");
    return 0;



if(isSubstring(s1,s2))
    printf("Yes");
else
    printf("No");

}
