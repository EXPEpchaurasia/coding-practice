#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode NODE;
struct TreeNode
{
    int val;
    NODE *lchild;
    NODE *rchild;
}TreeNode;

typedef struct Tree TREE;
struct Tree
{
        NODE *root;
}Tree;

TREE* getTree()
{
    TREE *newTree = (TREE *)malloc(sizeof(TREE));
    newTree->root = NULL;
    return newTree;
}

NODE *getNode(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
   newNode->val = data;
   newNode->lchild = newNode->rchild = NULL;
   return newNode;
}


void insertToBST(NODE *root, int data)
{
        if(data > root->val)
        {
            if(root->rchild)
                insertToBST(root->rchild,data);
            else
                root->rchild = getNode(data);
        }
        else if(root->lchild)
            insertToBST(root->lchild,data);
        else
            root->lchild = getNode(data);

        return;
}

void createBST(TREE *t)
{
        int n,data;
        printf("\nHow many elemnts :");
        scanf("%d",&n);
        if(n>0)
        {
            printf("\nEnter element :");
            scanf("%d",&data);
            t->root = getNode(data);
            --n;
            while(n--)
            {
                printf("\nEnter element :");
                scanf("%d",&data);
                insertToBST(t->root,data);
            }
        }
}


void printTreeInorder(NODE *root)
{
    if(root)
    {
        printTreeInorder(root->lchild);
        printf(" %d",root->val);
        printTreeInorder(root->rchild);
    }
}


void printTreeInorderWithLevel(NODE *root,int level)
{
    if(root)
    {
        printTreeInorderWithLevel(root->lchild,level+1);
        printf(" %d-(L%d)",root->val,level);
        printTreeInorderWithLevel(root->rchild,level+1);
    }
}


inline int max(int i, int j)
{
    return (i>j)?i:j;
}


void printNodeData(int val,int Lheight,int Rheight,int type)
{
    //printf("\nVal = %d    HeightLST = %d      HeightRST = %d        Retured at :%d",val,Lheight,Rheight,type);
}

int checkBalance(NODE *root)
{
    if(!root)
    return 0;

    int Lheight,Rheight;
    if(((Lheight = checkBalance(root->lchild))==-1) || ((Rheight = checkBalance(root->rchild))==-1))      //if any height is -1 then return NOT BALANCED FLAG
    {
        printNodeData(root->val,Lheight,Rheight,1);
        return -1;
    }

    if((Lheight == 0 && Rheight !=0) || (Rheight == 0 && Lheight != 0)) //if the node is NOT a leaf then return the height of subtree;
    {
        printNodeData(root->val,Lheight,Rheight,3);
        if(!Rheight)
            return Lheight+1;
        else
            return Rheight+1;
    }
    else if((Lheight - Rheight) > 1 || (Lheight - Rheight) < -1)//if NOT BALANCED
    {
        printNodeData(root->val,Lheight,Rheight,4);
        return -1;
    }
    else    //else return height of the tree
    {
        printNodeData(root->val,Lheight,Rheight,5);
        return (1+max(Lheight, Rheight));
    }
}


int isBalanced(NODE *root)
{
    return (!root)?1:((checkBalance(root) == -1)?0:1);
}


NODE *isPresent(NODE *root, int val)
{
    if(!root)
    return NULL;
    else
    {
        if(root->val == val)
            return root;
        else if(root->val < val)
            return isPresent(root->rchild,val);
        else
            return isPresent(root->lchild,val);
    }
}


NODE *searchNodeK(NODE *root, int *k)
{
    if(!root)
        return NULL;
    else
    {
        NODE *temp = searchNodeK(root->lchild, k);
        if(*k == 0)
            return temp;

        --(*k);
        if(*k == 0)
            return root;
        else
            return searchNodeK(root->rchild,k);
    }
}


NODE* findKthInOrder(NODE *root,int k)
{
    return searchNodeK(root, &k);
}

int main()
{
    TREE* t = getTree();
    createBST(t);

/*
    if(isBalanced(t->root)==1)
    printf("\nTree is Balanced.");
    else
    printf("\nTree is NOT Balanced");


    printTreeInorder(t->root);

{
    printf("\n\nEnter the node value to search.");
    int value;
    scanf("%d",&value);
    NODE *req = isPresent(t->root,value);
    if(req)
        printf("\nValue is present.");
    else
        printf("\nValue is Not present.");
}
*/

    while(1)
    {
        int k;
        printf("\n\nEnter the value of K to find Kth Node Inorder. :");
        scanf("%d",&k);
        if(k < 0)
            {printf("\nInvalid Node.");break;}
        NODE *kth = findKthInOrder(t->root,k);
        if(kth)
            printf("\n%d'th Node is %d",k,kth->val);
        else
            printf("\nNode Doesn't exists");
    }
    //printTreeInorderWithLevel(t->root,1);

    free(t);
    return 0;
}
