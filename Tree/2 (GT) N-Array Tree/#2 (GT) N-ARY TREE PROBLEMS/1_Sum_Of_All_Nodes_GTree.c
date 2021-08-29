
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
    struct NTNode *Child, *Sibling;
};
struct NTNode *Create_Root()
{
    int data;
    printf("Enter root node Data :");
    scanf("%d", &data);

    root = (struct NTNode *)malloc(sizeof(struct NTNode));
    root->data = data;
    root->Child = root->Sibling = NULL;
    return root;
}
struct NTNode *Add_Child(struct NTNode *root)
{
    int data;
    printf("Enter Child node Data  of %d : ", root->data);
    scanf("%d", &data);
    if (data != -1)
    {
        Cnode = (struct NTNode *)malloc(sizeof(struct NTNode));
        Cnode->data = data;
        Cnode->Child = NULL;
        Cnode->Sibling = NULL;

        root->Child = Cnode;

        return Cnode;
    }
    else
        return NULL;
}
void Add_Sibling(struct NTNode *C, struct Queue q)
{
    // after push root node  Queue is not empty.
    if (C != NULL)
    {
        while (1)
        {
            int data;
            printf("Enter Sibling node Data of %d : ", C->data);
            scanf("%d", &data);

            if (data != -1)
            {
                Snode = (struct NTNode *)malloc(sizeof(struct NTNode));
                Snode->data = data;
                Snode->Child = NULL;
                Snode->Sibling = NULL;

                C->Sibling = Snode;
                enqueue(Snode);
                C = Snode;
            }
            else
                break;
        }
    }
}
void Create_N_Ary_Tree()
{
    // Create a Queue for storing node address
    struct Queue q;
    CreateQueue(&q, 100);

    // initialy queue is empty
    // create new root node.
    struct NTNode *root = Create_Root();
    enqueue(root);

    while (!isEmpty(f))
    {
        struct NTNode *R = dequeue(f);

        struct NTNode *C = Add_Child(R);
        if (C != NULL)
            enqueue(C);

        Add_Sibling(C, q);
    }
}

int SumOfAllNodesRecur(struct NTNode *root)
{
    if (!root)
        return 0;
    return (root->data + SumOfAllNodesRecur(root->Child) + SumOfAllNodesRecur(root->Sibling));
}
int SumOfAllNodesIT(struct NTNode *root)
{
    struct Queue q;
    CreateQueue(&q, 100);

    enqueue(root);

    int sum = 0;
    while (!isEmpty(f))
    {

        root = dequeue(f);
        sum = sum + root->data;

        if (root->Child)
            enqueue(root->Child);
        if (root->Sibling)
            enqueue(root->Sibling);
    }

    return sum;
}
// Recursive Functions for Traversing:

int main()
{
    // Note : Root Node Doesn't have any Sibling !.
    Create_N_Ary_Tree();

    printf("Recursion : Sum Of All Nodes of generic tree is : %d\n", SumOfAllNodesRecur(root));
    printf("iteration : Sum Of All Nodes of generic tree is : %d\n", SumOfAllNodesIT(root));

    return 0;
}