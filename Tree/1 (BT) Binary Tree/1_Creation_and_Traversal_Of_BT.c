#include <stdio.h>
#include <stdlib.h>

// set global pointrs:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;

// Create Queue:
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

//Create Stack:
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
    {
        printf("Stack Underflow !\n");
    }
    else
    {
        x = st->Arr[st->top];
        st->top--;
        return x;
    }
}
struct BTNode *StackTop(struct stack *ptr)
{
    return ptr->Arr[ptr->top];
}

// Structure for binary tree node :
struct BTNode
{
    int data;
    struct BTNode *Lchild, *Rchild;
};
// Creation of Binary Tree:
void CreateBinaryTree()
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

//=============================    RECURSIVE TRAVERSAL    ==========================================================================================================

// Recursive Functions for BT Traversing:
int PreOrderTrav(struct BTNode *root)
{
    if (root)
    {
        printf(" %d ", root->data); // 1.goto root
        PreOrderTrav(root->Lchild); // 2.goto Left
        PreOrderTrav(root->Rchild); // 3.goto Right
    }
}
int InOrderTrav(struct BTNode *root)
{
    if (root)
    {
        InOrderTrav(root->Lchild);  //   1.goto left
        printf(" %d ", root->data); //  2.goto root
        InOrderTrav(root->Rchild);  //   3.goto Right
    }
}
int PostOrderTrav(struct BTNode *root)
{
    if (root)
    {
        PostOrderTrav(root->Lchild); // 1.goto Left
        PostOrderTrav(root->Rchild); // 2.goto Right
        printf(" %d ", root->data);  //  3.goto  root
    }
}

//=============================    ITERATIVE TRAVERSAL    ==========================================================================================================

//  Iterative Functions for BT Traversing:
void ItPreOrderTrav(struct BTNode *root)
{ // create stack
    struct stack s;
    createStack(&s, 100);
    while (1)
    {
        while (root)
        {
            printf(" %d ", root->data);
            push(&s, root);
            root = root->Lchild;
        }
        if (isEmptyS(&s))
            break;
        root = pop(&s);
        root = root->Rchild;
    }
}
void ItinOrderTrav(struct BTNode *root)
{ // create stack
    struct stack s;
    createStack(&s, 100);
    while (1)
    {
        while (root)
        {
            push(&s, root);
            root = root->Lchild;
        }
        if (isEmptyS(&s))
            break;
        root = pop(&s);
        printf(" %d ", root->data);
        root = root->Rchild;
    }
}
void ItPostOrderTrav(struct BTNode *root)
{ // create stack
    struct stack s;
    createStack(&s, 100);
    while (1)
    {
        if (root != NULL)
        {
            push(&s, root);
            root = root->Lchild;
        }
        else
        {
            if (isEmptyS(&s))
                break;
            else
            {
                if (StackTop(&s)->Rchild == NULL)
                {
                    root = pop(&s);
                    printf(" %d ", root->data);
                    while (root == StackTop(&s)->Rchild)
                    {
                        printf(" %d ", StackTop(&s)->data);
                        root = pop(&s);
                    }
                }

                if (!isEmptyS(&s))
                    root = StackTop(&s)->Rchild;

                else
                    root = NULL;
            }
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

int main()
{
    // Create Bianry Tree :
    CreateBinaryTree();

    //=============================    RECURSIVE TRAVERSAL    ==========================================================================================================

    printf("\nPre-Order Traversal is :");
    PreOrderTrav(root);

    printf("\nIn-Order Traversal is :");
    InOrderTrav(root);

    printf("\nPost-Order Traversal is :");
    PostOrderTrav(root);

    //=============================    ITERATIVE TRAVERSAL    ==========================================================================================================
     printf("\n");
    printf("\niterative : Level-Order Traversal is :");
    levelOrderTrav(root);

    printf("\niterative : pre-Order Traversal is :");
    ItPreOrderTrav(root);

    printf("\niterative : in-Order Traversal is :");
    ItinOrderTrav(root);

    printf("\niterative : Post-Order Traversal is :");
    ItPostOrderTrav(root);

    return 0;
}