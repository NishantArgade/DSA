#include <stdio.h>
#include <stdlib.h>

// create Queue:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;

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
struct BTNode
{
    int data;
    struct BTNode *Lchild, *Rchild;
};

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
        struct BTNode *node = dequeue(f);

        // 1. Create Left Node :
        int L;
        printf("For %d Parent Node : Enter data of \" Left node \" :", node->data);
        scanf("%d", &L);
        if (L != -1)
        {
            struct BTNode *LnewNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            LnewNode->data = L;
            LnewNode->Lchild = LnewNode->Rchild = NULL;
            node->Lchild = LnewNode;
            enqueue(LnewNode);
        }

        // 2. Create Right Node :
        int R;
        printf("For %d parent Node : Enter data of \" Right node \"  :", node->data);
        scanf("%d", &R);
        if (R != -1)
        {
            struct BTNode *RnewNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            RnewNode->data = R;
            RnewNode->Lchild = RnewNode->Rchild = NULL;
            node->Rchild = RnewNode;
            enqueue(RnewNode);
        }
    }
}

// Recursive Functions for Traversing:
int InOrderTrav(struct BTNode *root)
{
    if (root)
    {
        InOrderTrav(root->Lchild);  //   1.goto left
        printf(" %d ", root->data); //  2.goto root
        InOrderTrav(root->Rchild);  //   3.goto Right
    }
}

struct BTNode *inorderSuccessor(struct BTNode *root, struct BTNode *node)
{
    struct BTNode *ptr = root;
    if (node->Rchild != NULL)
    {
        node = node->Rchild;
        while (node->Lchild != NULL)
        {
            node = node->Lchild;
        }
        return node;
    }
    else
    {
        struct stack s;
        createStack(&s, 100);
        struct stack s1;
        createStack(&s1, 100);
        while (1)
        {
            while (ptr)
            {
                push(&s, ptr);
                ptr = ptr->Lchild;
            }
            if (isEmptyS(&s))
                break;
            ptr = pop(&s);

            if (ptr->data == node->data)
                break;

            ptr = ptr->Rchild;
        }
        ptr = pop(&s);
        return ptr;
    }
}
struct BTNode *PreorderSuccessor(struct BTNode *root, struct BTNode *node)
{
    struct BTNode *ptr = root;
    if (node->Lchild != NULL)
    {
        node = node->Lchild;
        return node;
    }
    else
    {
        struct stack s;
        createStack(&s, 100);
        struct stack s1;
        createStack(&s1, 100);
        while (1)
        {
            while (ptr)
            {
                push(&s, ptr);
                ptr = ptr->Lchild;
            }
            if (isEmptyS(&s))
                break;
            ptr = pop(&s);

            if (ptr == node)
                break;

            ptr = ptr->Rchild;
        }
        ptr = pop(&s);
        ptr = ptr->Rchild;
        return ptr;
    }
}

int main()
{
    CreateTree();

    printf("\nIn-Order Traversal is :");
    InOrderTrav(root);

    struct BTNode *node, *Ans;

    node = root->Lchild->Rchild;

    Ans = inorderSuccessor(root, node);
    printf("\n The inorder successor of %d is : %d", node->data, Ans->data);

    Ans = PreorderSuccessor(root, node);
    printf("\n The Preorder successor of %d is : %d", node->data, Ans->data);

    return 0;
}