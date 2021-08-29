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

// Create Stack :
struct stack
{
    int size;
    int top;
    struct BTNode **Arr;
};
void createStack(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->Arr = (struct BTNode **)malloc(st->size * sizeof(struct BTNode *));
}
int isEmptyS(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFullS(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
void push(struct stack *st, struct BTNode *x)
{
    if (isFullS(st))
    {
        printf("Stack is Overflow !\n");
    }
    else
    {
        st->top++;
        st->Arr[st->top] = x;
    }
}
struct BTNode *pop(struct stack *st)
{
    struct BTNode *x = NULL;
    if (isEmptyS(st))
        printf("Stack Underflow !\n");

    else
    {
        x = st->Arr[st->top];
        st->top--;
        return x;
    }
}

// Create Binary Tree :
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

void ZigZagTraversalOfTree(struct BTNode *root)
{
    struct Queue q;
    CreateQueue(&q, 100);

    struct stack s1;
    createStack(&s1, 100);
    push(&s1, root);

    struct stack s2;
    createStack(&s2, 100);

    struct BTNode *temp;

    while (!isEmptyS(&s1) || !isEmptyS(&s2))
    {
        while (!isEmptyS(&s1))
        {
            temp = pop(&s1);
            printf(" %d ", temp->data);

            if (temp->Lchild)
                push(&s2, temp->Lchild);

            if (temp->Rchild)
                push(&s2, temp->Rchild);
        }
        while (!isEmptyS(&s2))
        {
            temp = pop(&s2);
            printf(" %d ", temp->data);

            if (temp->Rchild)
                push(&s1, temp->Rchild);

            if (temp->Lchild)
                push(&s1, temp->Lchild);
        }
    }
}
int main()
{
    CreateTree();

    printf("Level-Order Traversal is :\n");
    levelOrderTrav(root);

    printf("ZigZag-Order Traversal is :\n");
    ZigZagTraversalOfTree(root);

    return 0;
}