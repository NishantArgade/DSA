#include <stdio.h>
#include <stdlib.h>

// Create Queue :
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;
int count = 0;

struct Node
{
    struct BTNode *data;
    struct Node *next;
};
struct Queue
{
    int size;
    int f;
    int r;
    struct BTNode *arr;
};
int isFull(struct Node *ptr)
{
    if (ptr == NULL) // if memory is not allow then pointer point to NULL (i.e Memory is full)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Node *ptr)
{
    if (f == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(struct BTNode *x)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(ptr))
    {
        printf("Queue is Full !\n");
    }
    else
        ptr->data = x;
    ptr->next = NULL;

    if (f == NULL) // if LinkList is Empty
    {
        f = r = ptr; // Queue is Empty
    }
    else
        r->next = ptr;
    r = ptr;
    count++;
}
struct BTNode *dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is Empty !\n");
    }
    else
        temp = f;
    f = f->next;
    struct BTNode *val = temp->data;
    free(temp);
    count--;
    return val;
}
void CreateQueue(struct Queue *q, int size)
{
    q->f = q->r = -1;
    q->size = size;
    q->arr = (struct BTNode *)malloc(q->size * sizeof(struct Node));
}

struct BTNode
{
    int data;
    struct BTNode *Lchild, *Rchild;
};

void CreateTree()
{
    // Create a Queue for storing node address
    struct Queue q;
    CreateQueue(&q, 100);

    // create root node
    // initialy queue is empty
    if (isEmpty(f))
    {
        int data;
        printf("Enter root node Data :");
        scanf("%d", &data);
        root = (struct BTNode *)malloc(sizeof(struct BTNode));
        root->data = data;
        root->Lchild = root->Rchild = NULL;
        enqueue(root);
    }

    // create new nodes
    // after push root node is not empty
    while (!isEmpty(f))
    {
        struct BTNode *p = dequeue(f);

        // 1. Create Left Node :
        int L;
        printf("For %d Parent Node : Enter data of \" Left node \" :", p->data);
        scanf("%d", &L);
        if (L != -1)
        {
            struct BTNode *LnewNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            LnewNode->data = L;
            LnewNode->Lchild = LnewNode->Rchild = NULL;
            p->Lchild = LnewNode;
            enqueue(LnewNode);
        }

        // 2. Create Right Node :
        int R;
        printf("For %d parent Node : Enter data of \" Right node \"  :", p->data);
        scanf("%d", &R);
        if (R != -1)
        {
            struct BTNode *RnewNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            RnewNode->data = R;
            RnewNode->Lchild = RnewNode->Rchild = NULL;
            p->Rchild = RnewNode;
            enqueue(RnewNode);
        }
    }
}
// Recursive Functions for Traversing:
void levelOrderTrav(struct BTNode *root)
{
    struct Queue q;
    CreateQueue(&q, 100);

    if (isEmpty(f))
    {
        printf(" %d ", root->data);
        enqueue(root);
    }
    while (!isEmpty(f))
    {
        root = dequeue(f);

        if (root->Lchild)
        {
            printf(" %d ", root->Lchild->data);
            enqueue(root->Lchild);
        }
        if (root->Rchild)
        {
            printf(" %d ", root->Rchild->data);
            enqueue(root->Rchild);
        }
    }
    printf("\n");
}
int getinorderind(int in[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i < inEnd; i++)
    {
        if (in[i] == data)
            ;
        return i;
    }
}
// Recursive Functions for Build Binary Tree:
struct BTNode *BuildTree(int Post[], int Postind, int in[], int inStart, int inEnd)
{

    if (inStart > inEnd)
        return NULL;

    struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
    newNode->data = Post[Postind];
    Postind--;//****

    // If inStart == inEnd  i.e Only one node exists(leaf node).
    if (inStart == inEnd)
    {
        newNode->Lchild = NULL;
        newNode->Rchild = NULL;
        return newNode;
    }
    // Find root index in inorder:
    int INind = getinorderind(in, inStart, inEnd, newNode->data);

    newNode->Rchild = BuildTree(Post, Postind, in, INind + 1, inEnd);//****
    newNode->Lchild = BuildTree(Post, Postind, in, inStart, INind - 1);//****

    return newNode;
}
int main()
{
    //Build Tree using Post and inorder Traversal :

    int Post[] = {6, 2, 4, 5, 3, 1};
    int in[] = {6, 2, 1, 4, 3, 5};

    //For post-order and in-order: start ind = 0 and end ind = n-1  .//****
    struct BTNode *newroot = BuildTree(Post, 5, in, 0, 5);

    printf("New Tree Level-Order Traversal is :\n");
    levelOrderTrav(newroot);

    return 0;
}