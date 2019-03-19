#include<stdio.h>
#include<malloc.h>
typedef struct Node *NODE;

struct LINK_LIST
{
    NODE head;
    NODE tail;
};

struct Node
{
    int data;
    NODE nxt;
}Node;

NODE getNode(int d)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if(!newNode)
        return NULL;

    newNode->data = d;
    newNode->nxt = NULL;

    return newNode;
}

int addNode(struct LINK_LIST *list, NODE item)
{
    if(list->tail)
    {
        list->tail->nxt = item;
        list->tail = list->tail->nxt;
    }
    else
        list->head = list->tail= item;

    return 0 ;
}

int printList(NODE head)
{

    if(!head)
    {
        printf("\nList is Empty.");
    }
    else
    {
        printf("\n\nThe list is :");
        while(head)
        {
            printf("%d ",head->data);
            head = head->nxt;
        }
    }
    return 0;
}

 NODE nthLast(struct LINK_LIST *list, int N)
{
    if(list->head && N>0)
    {
        NODE current_last = list->head;
        NODE current = list->head;

        while(--N)
        {
            current_last = current_last->nxt;
            if(!current_last)
                return NULL;
        }

        while(current_last->nxt)
        {
            current_last = current_last->nxt;
            current = current->nxt;
        }

        return current;
    }

    return NULL;
}

int removeDuplicates(struct LINK_LIST *list)
{
        if(!(list->head) || !(list->head->nxt))
        {return 0;}

        printf("\nREMOVING DUPLICATES ....\n");

        NODE pos,tracker,tracker_prev;
        pos = list->head;
        tracker = list->head->nxt;
        tracker_prev = list->head;
        int count = 0;
        while(pos->nxt)
        {
            while(tracker)
            {
                if(tracker->data == pos->data)
                {
                    tracker_prev->nxt = tracker->nxt;
                    free(tracker);
                    tracker = tracker_prev->nxt;
                    ++count;
                }
                else
                {
                    tracker_prev = tracker;
                    tracker = tracker->nxt;
                }
            }

            pos = pos->nxt;
            tracker = pos->nxt;
            tracker_prev = pos;
        }
    return count;
}

int createList(struct LINK_LIST *list, int n)
{
        int i,data;
        for(i = 0; i< n; ++i)
        {
             printf("Enter the elements :");
            scanf("%d",&data);
            NODE newNode = getNode(data);

            if(newNode)
                addNode(list,newNode);

        }
        return 0;
}

int freeList(struct LINK_LIST *list)
{
    NODE current = list->head;
    NODE temp = current;
    printf("\n\n\n*****FREEING THE LIST******");
    while(current)
    {
        current = current->nxt;
        printf("\nFreeing Element : %d",temp->data);
        free(temp);
        temp = current;
    }
    printf("\n\n*****FREEING LIST SUCCESSFULL******");
    return 0;
}

struct LINK_LIST *addSortedNODE(struct LINK_LIST *list,NODE temp)
{
    NODE current = list->head;

    if(temp->data < current->data)
    {
        temp->nxt  = list->head;
        list->head = temp;
    }
    else
    {
        while(current->nxt)
        {
            if((current->nxt->data) < (temp->data))
            {
                current = current->nxt;
            }
            else
            {
                temp->nxt = current->nxt;
                current->nxt = temp;
                return list;
            }
        }//end while

        temp->nxt = NULL;
        current->nxt = temp;
    }//end else

    return list;
}


int sortByInsertion(struct LINK_LIST *list)
{
    if(!(list->head) || !(list->head->nxt))
    {return 0;}

    NODE tracker = list->head->nxt;
    NODE trac_prev = list->head;
    NODE temp = NULL;
    while(tracker)
    {
        if(tracker->data < list->head->data)
        {
            temp = tracker;
            tracker = tracker->nxt;
            trac_prev->nxt = tracker;
            temp->nxt = list->head;
            list->head = temp;
           // printList(list->head);
        }
         else if(tracker->data < trac_prev->data)
         {
            temp = tracker;
            tracker = tracker->nxt;
            trac_prev->nxt = tracker;
            temp->nxt = NULL;
            list = addSortedNODE(list,temp);
           // printList(list->head);
         }
         else
         {
            trac_prev = tracker;
            tracker = tracker->nxt;
         }
    }//end while

}//end sortByInsertion

void reverseList(struct LINK_LIST *list)
{
    if(!(list->head))
        return;
    else if(list->head == list->tail)
        return;
    else
    {
        NODE prev = NULL;
        NODE current = list->head;
        list->tail = current;
        NODE nxt = current->nxt;
        while(nxt)
        {
            current->nxt = prev;
            prev = current;
            current = nxt;
            nxt= nxt->nxt;
        }
        current->nxt = prev;
        list->head = current;
    }
}


NODE mergeList(NODE head1, NODE head2)
{

    if(!head1)
        return head2;
    if(!head2)
        return head1;

    NODE resultHead, prev;

    if(head1->data <= head2->data)
        resultHead = head1;
    else
        resultHead = head2;

    prev = NULL;
    while(head2)
    {
        while( ( head1 ) && ( head1->data <= head2->data ) )
        {
            prev = head1;
            head1 = head1->nxt;
        }
        if(prev)
        {
            prev->nxt = head2;
            prev = NULL;
        }
        if(!(head1))
            break;

        while( ( head2 ) && ( head2->data <= head1->data ) )
        {
            prev = head2;
            head2 = head2->nxt;
        }
        if(prev)
        {
            prev->nxt = head1;
            prev = NULL;
        }
    }

    return resultHead;
}

int main( int argc, char *argv[] )
{
        int n,n2,data,i,Nthlast;
        printf("How many elements :");
        scanf("%d",&n);

        struct LINK_LIST list,list2;
        list.head = list.tail = NULL;
        list2.head = list2.tail = NULL;
        createList(&list,n);
        printf("\n\nHow many elements in list 2:");
        scanf("%d",&n2);
        createList(&list2,n2);

        printList(list.head);
        printList(list2.head);


        list.head = mergeList(list.head, list2.head);
        printf("\nResult List :");
        printList(list.head);

        //reverseList(&list);
        //printList(list.head);

    //finding the Nth last number
    /*
    {
        printf("\n Value of N to find the Nth last ?: ");
        scanf("%d",&Nthlast);
        if(nthLast(&list,Nthlast))
            printf("\n Nth last is : %d",nthLast(&list,Nthlast)->data);
        else
            printf("\n Nth last number does NOT exists in the list :(");
    }
*/
    //removing the duplicates from the link list
/*
    {

       printf("Number of duplicates removed are : %d",removeDuplicates(&list));
       printf("\n\nAfter Removing the duplicates...");
       printList(list.head);
    }
    */

//sorting the list
/*
    {
        printf("\nSORTING THE LIST...");
        sortByInsertion(&list);
        printf("\nAfter sorting.");
        printList(list.head);
    }
*/
    freeList(&list);
        return 0;
}
