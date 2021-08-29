
//2. Ways to represent N- Ary Tree(Generic Tree )(Recomended ):

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

struct NTNode
{
    int data;
    struct NTNode *Child;
};



struct NTNode * Build_K_AryTree(int Arr[], int n,int k,int ind)
{
    int i = 0, node = 1;

    struct NTNode *NewNode = (struct NTNode *)malloc(sizeof(struct NTNode));
    NewNode->data = Arr[ind];
    NewNode->Child = (struct NTNode *)malloc(k * sizeof(struct NTNode));
    // NewNode->Child = NULL;

    for (int i = 0; i<k; i++)
    {
        if (k * ind + i < n)
        {
             ind++;
            // NewNode->Child[i] = Build_K_AryTree(Arr, n, k,ind);
        }
        else 
          NewNode->Child[i]=NULL;
    }
    return NewNode;
}

int main()
{
    // Note : Root Node Doesn't have any Sibling !.
    // Create_N_Ary_Tree();

    int Arr[] = {1, 2, 5, 6, 7, 3, 8, 9, 10, 4};
    int n =10,k=3,ind =0;
    struct NTNode *newroot = Build_K_AryTree(Arr, n, k,ind);
    
    return 0;
}