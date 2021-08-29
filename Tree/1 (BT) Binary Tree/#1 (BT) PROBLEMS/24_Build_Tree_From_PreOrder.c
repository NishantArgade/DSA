#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// set global Queue's pointers:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;

struct BTNode
{
    char data;
    struct BTNode *Lchild, *Rchild;
};
// Create Queue :
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

    return val;
}
void CreateQueue(struct Queue *q, int size)
{
    q->f = q->r = -1;
    q->size = size;
    q->arr = (struct BTNode *)malloc(q->size * sizeof(struct Node));
}

void levelOrderTrav(struct BTNode *root)
{
    struct Queue q;
    CreateQueue(&q, 100);

    if (isEmpty(f))
    {
        printf(" %c ", root->data);
        enqueue(root);
    }
    while (!isEmpty(f))
    {

        root = dequeue(f);

        if (root->Lchild)
        {
            printf(" %c ", root->Lchild->data);
            enqueue(root->Lchild);
        }
        if (root->Rchild)
        {
            printf(" %c ", root->Rchild->data);
            enqueue(root->Rchild);
        }
    }
}

struct BTNode *BuildTreeFromPreOrder(char *Pre, int i)
{
    struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
    newNode->data = Pre[i];
    newNode->Lchild = newNode->Rchild = NULL;

    if (Pre[i] == 'L')
        return newNode;

    i++;
    newNode->Lchild = BuildTreeFromPreOrder(Pre, i);
    i++;
    newNode->Rchild = BuildTreeFromPreOrder(Pre, i);

    return newNode;
}

int main()
{

    char PreOrder[] = {'I', 'L', 'I','L','L'};
    struct BTNode *newroot = BuildTreeFromPreOrder(PreOrder, 0);
    printf("level order traversal is : \n");
    levelOrderTrav(newroot);

    return 0;
}
