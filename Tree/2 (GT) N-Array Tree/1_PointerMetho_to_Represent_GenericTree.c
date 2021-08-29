
//1. Way to represent N- Ary Tree(Generic Tree ):(don't Recomended !)

#include <stdio.h>
#include <stdlib.h>

// Global pointers:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct NTNode *root, *Cnode, *Snode; // Cnode = Child Node,Snode = Sibling node.

// create Queue:
struct Node
{
    struct NTNode *data;
    struct Node *next;
};
struct Queue
{
    int size;
    int f;
    int r;
    struct NTNode *arr;
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
void enqueue(struct NTNode *x)
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
struct NTNode *dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is Empty !\n");
    }
    else
        temp = f;
    f = f->next;
    struct NTNode *val = temp->data;
    free(temp);

    return val;
}
void CreateQueue(struct Queue *q, int size)
{
    q->f = q->r = -1;
    q->size = size;
    q->arr = (struct NTNode *)malloc(q->size * sizeof(struct Node));
}

struct NTNode//<- N-Ary Tree Node.
{
    int data;
    struct NTNode *Child1, *Child2, *Child3, *Child4, *Child5, *Child6 ;
};
struct NTNode *CreateNewNode(int data)
{
    root = (struct NTNode *)malloc(sizeof(struct NTNode));
    root->data = data;
    root->Child1 = root->Child2 = root->Child3 = root->Child4 = root->Child5 = root->Child6 = NULL;
    return root;
}

int main()
{
    struct NTNode *root = CreateNewNode(1);
    root->Child1 = CreateNewNode(2);
    root->Child2 = CreateNewNode(3);
    root->Child3 = CreateNewNode(4);
    root->Child1->Child1 = CreateNewNode(5);
    root->Child1->Child2 = CreateNewNode(6);
    root->Child2->Child1 = CreateNewNode(7);

    printf(" %d ", root->data);
    printf(" %d ", root->Child1->data);
    printf(" %d ", root->Child2->data);
    printf(" %d ", root->Child3->data);
    printf(" %d ", root->Child1->Child1->data);
    printf(" %d ", root->Child1->Child2->data);
    printf(" %d ", root->Child2->Child1->data);

    return 0;
}