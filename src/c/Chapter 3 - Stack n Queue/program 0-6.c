//program to implement STACK as singly linked list

#include<stdio.h>
#include<malloc.h>

typedef struct Node NODE;
struct STACK
{
    NODE *top;
    int currheight;
}STACK;

struct Node
{
    int val;
    NODE *nxt;
};

NODE* getNode(int val)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->val = val;
    newNode->nxt = NULL;
    return newNode;
}

void push(struct STACK *stack, int val)
{
    if(!(stack->top))
    {
        stack->top = getNode(val);
    }
    else
    {
        NODE *newNode = getNode(val);
        newNode ->nxt = stack->top;
        stack->top = newNode;
    }
    stack->currheight++;
    return ;
}

int pop(struct STACK * stack)
{
    if(stack->top)
    {
        NODE *temp = stack->top;
        int item = temp->val;
        stack->top = stack->top->nxt;
        free(temp);
        stack->currheight--;
        return item;
    }

    printf("\nSTACK UNDERFLOW.\n");
    return -1;
}

struct STACK * getStack()
{
    struct STACK *newStack = (struct STACK *)malloc(sizeof(struct STACK));
    newStack->top = NULL;
    newStack->currheight = 0;
    return newStack;
}

void createStack(struct STACK *stack)
{
    int n,item,i;
    printf("How many elements ? :");
    scanf("%d",&n);
    i=0;
    while((i++)<n)
    {
        printf("\nEnter element :");
        scanf("%d",&item);
        push(stack,item);
    }
    return;
}

void emptyStack(struct STACK *stack)
{
    printf("\n******Now POPPING.*****\n");

    while(stack->top)
        printf("%d ",pop(stack));//,stack->currheight);

    return;
}

typedef struct QUEUE Que;
struct QUEUE
{
  NODE *head;
};

void question1()
{
    printf("\n\n_____IMPLEMENTING QUEUE AS LINKED LIST____\n");

}

int peek(struct STACK *stack)
{
    if(stack->top)
    {
        return stack->top->val;
    }

     printf("\nSTACK EMPTY while peeping\n");
     return -1;
}

void sortStack(struct STACK *original)
{
        if(!original->top)  //if stack is empty
            return;

        int temp;
        struct STACK *dummy = getStack();

        while(original->top)    //put whole of original stack into dummy in reverse order.
            push(dummy,pop(original));


        while(dummy->top)
        {
            if(!original->top)  //if original stack is empty, simply push the top most elemnt of dummy in it
                push(original,pop(dummy));
            else
            {
                temp = pop(dummy);

                if(temp <= peek(original))  //if top of dummy is less than top of original, simply push it in original.
                    push(original,temp);
                else        //else pop original and push it into dummy untill temp is less than original's top or original is empty, then push temp in original stack.
                {
                    while((original->top) && (temp > peek(original)))
                        push(dummy,pop(original));

                    push(original,temp);

                }//endelse
            }//end else
        }//end while
        free(dummy);
}


int main()
{
    struct STACK *stack = getStack();
    createStack(stack);
    sortStack(stack);
    emptyStack(stack);
    free(stack);

//    question1();

}
