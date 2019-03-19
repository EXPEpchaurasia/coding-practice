#include<stdio.h>
#include<malloc.h>

typedef struct Alphbet *ABT;
struct Alphbet
{
    char ch;
    ABT nxt;
}Alphbet;

typedef struct LINK_LIST *LIST;
struct LINK_LIST
{
        ABT head;
        ABT tail;
}LINK_LIST;

ABT getABT(char ch)
{
    ABT newNode = (ABT)malloc(sizeof(struct Alphbet));
    if(newNode)
    {
        newNode->ch = ch;
        newNode->nxt = NULL;
    }
    return newNode;
}

void printlist(LIST list)
{
    if(list->head)
    {
        ABT current = list->head;
        printf("\n PRINTING : ");
        while(current)
        {
            printf("%c",current->ch);
            current = current->nxt;
        }
    }
}

void insertAfter(LIST list, ABT head, ABT next)
{
    next->nxt = head->nxt;
    head->nxt = next;
}

void removeAfter(ABT current)
{
    ABT toRem = current->nxt;
    current->nxt  = toRem->nxt;
    toRem->nxt = NULL;
}

/*
void permute(LIST list, char *arr, int currAlph)
{
    if(arr[currAlph] == '\0')
    {printlist(list);return;}
    printf("\nEncountered ALBT %c",arr[currAlph]);
    ABT newNode = getABT(arr[currAlph]);
    if(!(list->head))
    {
        list->head = list->tail = newNode;
    }
    else
    {
        newNode->nxt = list->head;
        list->head = newNode;
    }

    permute(list, arr, currAlph+1);

    list->head = list->head->nxt;
    newNode->nxt = NULL;
    ABT current = list->head;

    while(current!=(list->tail))
    {
        printf("\n here 1.\n");
        //insertAfter(list, current, newNode);
        newNode->nxt = current->nxt;
        current -> nxt = newNode;
        permute(list,arr,currAlph+1);
        current->nxt = current->nxt->nxt;
        newNode->nxt = NULL;
        //removeAfter(current);
    }

    list->tail->nxt = newNode;
    ABT listprev = list->tail;
    list->tail = list->tail->nxt;

    permute(list,arr,currAlph+1);

    list->tail = listprev;
    free(list->tail->nxt);
    list->tail->nxt = NULL;

    return;
}
*/


 void permute(char list[],int k, int m)
 {
      int i;
    char temp;
    if(k==m)
    {
         /* PRINT A FROM k to m! */
         for(i=0;i<3;i++)
         {
             printf("%c",list[i]);
          }
         printf("\n");
    }
     else
    {
        for(i=k;i<m;i++)
        {
            /* swap(a[i],a[m-1]); */
            temp=list[i];
            list[i]=list[m-1];
            list[m-1]=temp;

            permute(list,k,m-1);

            /* swap(a[m-1],a[i]); */
            temp=list[m-1];
            list[m-1]=list[i];
            list[i]=temp;
        }
    }
}

int main()
{
    char arr[50];
   // printf("Enter the string. :");
    //scanf("%s",arr);
    struct LINK_LIST l;
    l.head = l.tail = NULL;
    //permute(&l,arr,0);

    char list[3]={'a','b','c'}; permute(list,0,3);

}
