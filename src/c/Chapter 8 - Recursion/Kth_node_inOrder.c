#include<stdio.h>

typedef struct node *NODE;
struct node
{
        int element;
        NODE lptr, rptr;
        int LSTcount;           //keeps the number of elements in left subtree including itself
};

NODE head = NULL;
void insertBST(NODE, int);
void printInorderBST(NODE);
void findKthInorder(NODE, int);

int main()
{
    FILE *fptr;
    fptr = fopen("abc.txt","r");
    if(!fptr)
    {
            printf("Unable to open.");
            exit(1);
    }
    int val;
    while(fscanf(fptr,"%d",&val)!=EOF)
    {
            insertBST(head,val);
    }
    fclose(fptr);
    printInorderBST(head);
    printf("Number 13 ");
     findKthInorder(head, 13);
    return 0;
}

void findKthInorder(NODE ptr, int k)
{
    if(ptr->LSTcount == k)
    {
            printf("Element is : %d",ptr->element);
            return;
    }
    else if(ptr->LSTcount > k)
            findKthInorder(ptr->lptr, k);
    else
            findKthInorder(ptr->rptr, k-(ptr->LSTcount));

            return;

}

void printInorderBST(NODE ptr)
{
        if(!ptr)
            return;

        printInorderBST(ptr->lptr);
        printf("%d -(%d)\n",ptr->element,ptr->LSTcount);
        printInorderBST(ptr->rptr);
        return;
}

void insertBST(NODE nodePtr, int val)
{
            NODE parent = NULL;
            NODE current = nodePtr, newNode;

            newNode = (NODE)malloc(sizeof(struct node));
            newNode->element = val;
            newNode->lptr = newNode->rptr = NULL;
            newNode->LSTcount = 1;

            if(head == NULL)
            {
                    head = newNode;
                    return;
            }
            while(current != NULL)
            {
                    if(val < current->element)
                    {
                        ++(current->LSTcount);
                        parent = current;
                        current = current->lptr;
                    }
                    else
                    {
                      parent = current;
                      current = current->rptr;
                    }
            }

            if(val > parent->element)
            {
                parent->rptr = newNode;
            }
            else
            {
                parent->lptr = newNode;
            }
            return;
}
