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

int Currsizeofqueue()
{
    return count;
}
int findLevelWithgivenSum(struct BTNode *root, int givenSum)
{
    struct Queue q;
    CreateQueue(&q, 100);
    int sum = 0;

    enqueue(root);

    while (1)
    {
        int size = Currsizeofqueue();
        if (size == 0)
            break;
        int Levelsum = 0;
        while (size > 0)
        {
            root = dequeue(f);

            Levelsum = Levelsum + root->data;

            if (root->Lchild)
                enqueue(root->Lchild);
            if (root->Rchild)
                enqueue(root->Rchild);

            size--;
        }
        if (Levelsum == givenSum)
        {
            return 1;
        }
    }
    return 0;
}
void printpath(int path[], int pathlen)
{
    for (int i = 0; i < pathlen; i++)
    {
        printf(" %d ", path[i]);
    }
    printf("\n");
}
int ispathExists(int path[], int pathlen, int givensum)
{

    int sum = 0;
    for (int i = 0; i < pathlen; i++)
    {
        sum = sum + path[i];
    }
    if (sum == givensum)
    {
        printf("For given Sum Path is \"exits\" for path : \n");
        printpath(path, pathlen);
    }

    else
    {
        printf("For given Sum Path is \"not exits\" for path : \n");
        printpath(path, pathlen);
    }
}

int findPathWithgivenSum(struct BTNode *root, int path[], int pathlen, int givensum)
{
    if (root == NULL)
        return root->data;

    path[pathlen] = root->data;
    pathlen++;

    if (!root->Lchild && !root->Rchild)
        (ispathExists(path, pathlen, givensum));

    findPathWithgivenSum(root->Lchild, path, pathlen, givensum);
    findPathWithgivenSum(root->Rchild, path, pathlen, givensum);
}

int main()
{
    CreateTree();

    printf("Level-Order Traversal is :\n");
    levelOrderTrav(root);
    printf("For LEVEL : The LEVEL is Exists or not for given sum ? : %d \n", findLevelWithgivenSum(root, 5));
    
    int path[100];
    int pathlen = 0;
    printf("For PATH : The PATH is exists or not for given sum ? : %d\n ", findPathWithgivenSum(root, path, pathlen, 5));

    return 0;
}