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

struct BTNode *LowestCommonAncestor(struct BTNode *root, struct BTNode *node1, struct BTNode *node2)
{
    struct BTNode *left, *right;
    if (root == NULL)
        return NULL;

    if (root->data == node1->data || root->data == node2->data)
        return root;

    left = LowestCommonAncestor(root->Lchild, node1, node2);
    right = LowestCommonAncestor(root->Rchild, node1, node2);

    if (left == NULL && right == NULL)
        return NULL;

    if (left && right == NULL)
        return left;

    if (left == NULL && right)
        return right;

    if (left && right)
        return root;
}
int distanceFromLCAToNode(int dis, struct BTNode *LCA, struct BTNode *node)
{
    if (LCA == NULL)
        return 0;

    if (LCA->data == node->data)
        return dis;

    int left = distanceFromLCAToNode(dis + 1, LCA->Lchild, node);

    int Right = distanceFromLCAToNode(dis + 1, LCA->Rchild, node);

    if (left == 0 && Right == 0)
        return 0;
        
    if (left && Right == 0)
        return left;
    else
        return Right;
}
// int distanceFromLCAToNode(int dis, struct BTNode *LCA, struct BTNode *node)
// {
//     if (LCA == NULL)
//         return -1;
//     if (LCA->data == node->data)
//         return dis;
//     int d = distanceFromLCAToNode(dis + 1, LCA->Lchild, node);
//     if (d != -1)
//         return d;
//     d = distanceFromLCAToNode(dis + 1, LCA->Rchild, node);
//     return d;
// }
int Distance_bet_Two_Nodes(struct BTNode *root, struct BTNode *node1, struct BTNode *node2)
{
    struct BTNode *LCA = LowestCommonAncestor(root, node1, node2);
    int dis1 = distanceFromLCAToNode(0, LCA, node1);
    int dis2 = distanceFromLCAToNode(0, LCA, node2);
    int total = dis1 + dis2;
    return total;
}
int main()
{
    CreateTree();

    printf("Level-Order Traversal is :\n");
    levelOrderTrav(root);

    struct BTNode *node1 = (struct BTNode *)malloc(sizeof(struct BTNode));
    node1->data = 30;
    node1->Lchild = node1->Rchild = NULL;
    struct BTNode *node2 = (struct BTNode *)malloc(sizeof(struct BTNode));
    node2->data = 60;
    node2->Lchild = node2->Rchild = NULL;

    printf("Distance Between Two Nodes is : %d \n", Distance_bet_Two_Nodes(root, node1, node2));

    return 0;
}