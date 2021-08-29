#include <stdio.h>
#include <stdlib.h>

// Create Queue :
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTreeNode *root;
int count = 0;

struct Node
{
    struct BTreeNode *data;
    struct Node *next;
};
struct Queue
{
    int size;
    int f;
    int r;
    struct BTreeNode *arr;
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
void enqueue(struct BTreeNode *x)
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
struct BTreeNode *dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is Empty !\n");
    }
    else
        temp = f;
    f = f->next;
    struct BTreeNode *val = temp->data;
    free(temp);
    count--;
    return val;
}
void CreateQueue(struct Queue *q, int size)
{
    q->f = q->r = -1;
    q->size = size;
    q->arr = (struct BTreeNode *)malloc(q->size * sizeof(struct Node));
}

struct BTreeNode
{
    int data;
    struct BTreeNode *Lchild, *Rchild;
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
        root = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
        root->data = data;
        root->Lchild = root->Rchild = NULL;
        enqueue(root);
    }

    // create new nodes
    // after push root node is not empty
    while (!isEmpty(f))
    {
        struct BTreeNode *p = dequeue(f);

        // 1. Create Left Node :
        int L;
        printf("For %d Parent Node : Enter data of \" Left node \" :", p->data);
        scanf("%d", &L);
        if (L != -1)
        {
            struct BTreeNode *LnewNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
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
            struct BTreeNode *RnewNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
            RnewNode->data = R;
            RnewNode->Lchild = RnewNode->Rchild = NULL;
            p->Rchild = RnewNode;
            enqueue(RnewNode);
        }
    }
}
void levelOrderTrav(struct BTreeNode *root)
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

// Recursive Functions for get maxHeight of Subtrees:
int RE_MaxHeightOfTree(struct BTreeNode *root)
{
    if (root == NULL)
        return 0;

    int left_H = RE_MaxHeightOfTree(root->Lchild);
    int right_H = RE_MaxHeightOfTree(root->Rchild);
    int h;

    if (left_H > right_H)
        h = 1 + left_H;
    else
        h = 1 + right_H;

    return h;
}
int isBalance_Using_HeightOfTree(struct BTreeNode *root)
{
    if (!root)
        return 0;

    int left_H = RE_MaxHeightOfTree(root->Lchild);
    int right_H = RE_MaxHeightOfTree(root->Rchild);

    if (left_H - right_H == 0)
        return 1;
    else
        return 0;
}

int main()
{
    CreateTree();

    printf("\nLevel-Order Traversal is :");
    levelOrderTrav(root);

    // NOTE: Tree is Balanced if and only if "Height of Left subtree" == "Height of Right Subtree".

    (isBalance_Using_HeightOfTree(root)) ? printf("\nGiven BT is balanced") : printf("\nGiven BT is Unbalanced!");
    return 0;
}