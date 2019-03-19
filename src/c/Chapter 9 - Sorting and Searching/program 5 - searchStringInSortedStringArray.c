#include<stdio.h>
#include<string.h>

char sortedStrings[8][8] = {"at","ata","","ball","","car","dad","dada"};

int findStringLocation(char *source)
{
    int foundTill = -1;
    int length = strlen(source);
    int stringNumber = 0;
    for(stringNumber = 0; stringNumber < 8; ++stringNumber)
    {
        if(sortedStrings[stringNumber][0])
        {
            printf("\n Processing string %s", sortedStrings[stringNumber]);
            int currentChar = 0;
            for(currentChar = 0; currentChar <= foundTill ; ++currentChar)
            {
                if(sortedStrings[stringNumber][currentChar] != source[currentChar])
                    return -1;
            }

            while(source[currentChar] == sortedStrings[stringNumber][currentChar] && source[currentChar] != '\0')   //while the string matched with the source and source string iw still remaining
            {
                ++currentChar;++foundTill;
            }

            if(foundTill == length-1)//if string is matched till the end, then
            {
                if(sortedStrings[stringNumber][currentChar] == '\0') //if source string matched perfectly from a string in array
                    return stringNumber;
                else
                    return -1; //first matched string is larger than required hence source string does not exists.
            }
            if(source[currentChar] < sortedStrings[stringNumber][currentChar])
                return -1;
        }
    }
    return -1;
}

int main()
{
    int i,j;
    char mYstring[10];
    printf("\n\nEnter the string to find. :");
    scanf("%s",mYstring);
    if(mYstring[0] == '0')
        break;
    int loc findStringLocation(mYstring);
    if(loc != -1)
        printf("\n\nString found...!!! Location is at index %d",loc);
    else
        printf("\nString Not found");

return 0;
}
