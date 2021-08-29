#include <stdio.h>
#include <stdlib.h>

// set global pointrs:
struct BSTnode *curr;
struct BSTnode *q = NULL;
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BSTnode *p = NULL;
struct BSTnode
{
    int data;
    struct BSTnode *Lchild, *Rchild;
} *root = NULL;

// Create Queue:
struct Node
{
    struct BSTnode *data;
    struct Node *next;
};
struct Queue
{
    int size;
    int f;
    int r;
    struct BSTnode *arr;
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
void enqueue(struct BSTnode *x)
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
struct BSTnode *dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is Empty !\n");
    }
    else
        temp = f;
    f = f->next;
    struct BSTnode *val = temp->data;
    free(temp);

    return val;
}
void CreateQueue(struct Queue *q, int size)
{
    q->f = q->r = -1;
    q->size = size;
    q->arr = (struct BSTnode *)malloc(q->size * sizeof(struct Node));
}

struct BSTnode *CreateBSTree(struct BSTnode *root)
{

    int i = 0, n;
    printf("Enter number of nodes you want to inserted : ");
    scanf("%d", &n);

    while (i < n)
    {
        struct BSTnode *curr = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        int data;
        printf("Enter new node data : ");
        scanf("%d", &data);
        curr->data = data;
        curr->Lchild = curr->Rchild = NULL;

        if (root == NULL)
            root = curr;

        else
        {
            q = root;
            while (1)
            {
                if (curr->data < q->data)
                {
                    if (q->Lchild == NULL)
                    {
                        q->Lchild = curr;
                        break;
                    }
                    else
                        q = q->Lchild;
                }
                else
                {
                    if (q->Rchild == NULL)
                    {
                        q->Rchild = curr;
                        break;
                    }
                    else
                        q = q->Rchild;
                }
            }
        }
        i++;
    }
    return root;
}
void inOrder(struct BSTnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    printf(" %d ", root->data);
    inOrder(root->Rchild);
}

void rangePrint(struct BSTnode *root, int K1, int K2)
{
    if (!root)
        return;

    struct Queue q;
    CreateQueue(&q, 100);
    enqueue(root);

    while (!isEmpty(f))
    {
        p = dequeue(f);

        if (p->data >= K1 && p->data <= K2)
            printf(" %d ", p->data);

        if (p->data >= K1)
            enqueue(p->Lchild);
        if (p->data <= K2)
            enqueue(p->Rchild);
    }
}

int main()
{
    root = CreateBSTree(root);
    inOrder(root);

    int K1, K2;
    printf("\nEnter K1 and K2 : \n");
    scanf("%d"
          "%d",
          &K1, &K2);
    printf("The element Between Range K1 and K2 is : ");
    rangePrint(root, K1, K2);
    return 0;
}