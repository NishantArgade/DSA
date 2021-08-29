
//2. Way to represent N- Ary Tree(Generic Tree )(Recomended ):

#include <stdio.h>
#include <stdlib.h>

// Global pointers:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct NTNode *root1, *root2, *Cnode, *Snode; // Cnode = Child Node,Snode = Sibling node.

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

struct NTNode // N-Ary Tree Node.
{
    int data;
    struct NTNode *Child, *Sibling;
};
struct NTNode *Create_Root(struct NTNode *root)
{
    int data;
    printf("Enter root:");
    scanf("%d", &data);
    if (data != -1)
    {
        root = (struct NTNode *)malloc(sizeof(struct NTNode));
        root->data = data;
        root->Child = root->Sibling = NULL;
        return root;
    }
    else
        return NULL;
}
struct NTNode *Add_Child(struct NTNode *root)
{
    int data;
    printf("Enter Child of %d : ", root->data);
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
     struct NTNode * rootname =C;
  
    // after push root node  Queue is not empty.
    if (C != NULL)
    {
        while (1)
        {
            int data;
            printf("for %d : Enter Sibling of %d : ",rootname->data ,C->data);
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
struct NTNode *Create_N_Ary_Tree(struct NTNode *root)
{
    // Create a Queue for storing node address
    struct Queue q;
    CreateQueue(&q, 100);

    // initialy queue is empty
    // create new root node.
    root = Create_Root(root);
    if (root != NULL)
    {
        enqueue(root);
    }
    else
        return NULL;

    while (!isEmpty(f))
    {
        struct NTNode *R = dequeue(f);

        struct NTNode *C = Add_Child(R);
        if (C != NULL)
            enqueue(C);

        Add_Sibling(R, q);
    }
    return root;
}

int AreIsomorphic(struct NTNode *root1, struct NTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 && root2 == NULL || root1 == NULL && root2)
        return 0;
    return (AreIsomorphic(root1->Child, root2->Child) && AreIsomorphic(root1->Sibling, root2->Sibling));
}
int AreQuasiIsomorphic(struct NTNode *root1, struct NTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 && root2 == NULL || root1 == NULL && root2)
        return 0;
    return(AreQuasiIsomorphic(root1->Sibling, root2->Child) && AreQuasiIsomorphic(root1->Child, root2->Sibling));
}
int main()
{ // Note : Root Node Doesn't have any Sibling !.
    root1 = Create_N_Ary_Tree(root1);
    root2 = Create_N_Ary_Tree(root2);

    // Iso-Morphic means same form here data is not matter.
    // If Two Trees root1 and root2 are "quasi-IsoMorphic" means root1 can transform into root2 by swapping Some child and sibling of root1.
    // printf("Given Two GTree is Isomorphic or not %d\n", AreIsomorphic(root1, root2));
    printf("Given Two GTree is Quasi Isomorphic or not %d\n", AreQuasiIsomorphic(root1, root2));
    return 0;
}