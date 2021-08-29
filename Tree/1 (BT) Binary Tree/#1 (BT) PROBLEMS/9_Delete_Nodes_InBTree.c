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
    int data;
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
int count = 0;
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

// Create Binary Tree :
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
}

// Recursive Function for deletion of ALL BTree Nodes:
int DeletionOfALLBtreeNodes(struct BTNode *root)
{
    if (root == NULL)
        return 0;
    DeletionOfALLBtreeNodes(root->Lchild);
    DeletionOfALLBtreeNodes(root->Rchild);
    free(root);
}
// Deletion of Node With the help of data;
void DelOfBTNodewithDATA(struct BTNode *root, int data)
{
    struct Queue q;
    CreateQueue(&q, 50);
    struct BTNode *Temproot, *temp, *Delnode, *Lastnode;
    enqueue(root);
    while (!isEmpty(f))
    {
        Temproot = dequeue(f);
        if (Temproot->data == data)
            Delnode = Temproot;

        if (Temproot->Lchild)
            enqueue(Temproot->Lchild);
        if (Temproot->Rchild)
            enqueue(Temproot->Rchild);
    }
    Lastnode = Temproot;
    temp->data = Delnode->data;
    Delnode->data = Lastnode->data;
    Lastnode->data = temp->data;
    free(Lastnode);
  
}
int main()
{
    CreateTree();

    printf("\niterative : Level-Order Traversal Before \"DeletionOfAllBTreeNodes\" func  is :");
    levelOrderTrav(root);

    // DeletionOfALLBtreeNodes(root);
    // printf("\nLevel-Order Traversal After \"DeletionOfAllBTreeNodes\" func is :");
    // levelOrderTrav(root);

    int x;
    printf("Enter Node which u want to deleted : ");
    scanf("%d", &x);
    int data = x;
    DelOfBTNodewithDATA(root, data);
    printf("\nLevel-Order Traversal After Deletion of Node %d is :", data);
    levelOrderTrav(root);

    return 0;
}
