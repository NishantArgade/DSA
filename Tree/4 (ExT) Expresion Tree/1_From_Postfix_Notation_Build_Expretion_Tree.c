#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create Queue:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;

struct BTNode
{
    char data;
    struct BTNode *Lchild, *Rchild;
};
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

int isOperator(char ope)
{
    if (ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '%')
        return 1;
    else
        return 0;
}
struct BTNode * CreateExpresionTree(char *Exp, int n)
{
    struct stack s;
    createStack(&s,100);

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(Exp[i]))
        {
             struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            newNode->data = Exp[i];
            newNode->Lchild = newNode->Rchild = NULL;
            push(&s,newNode);
        }
        else{
            struct BTNode* T2 = pop(&s);
            struct BTNode* T1 = pop(&s);

            struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
            newNode->data = Exp[i];
            newNode->Lchild = T1; 
            newNode->Rchild = T2;
            push(&s,newNode);
        }
    }
    root = pop(&s);
    return root;
}

// Recursive Functions for Traversing:
int InOrderTrav(struct BTNode *root)
{
    if (root)
    {
        InOrderTrav(root->Lchild);  //   1.goto left
        printf("%c", root->data); //  2.goto root
        InOrderTrav(root->Rchild);  //   3.goto Right
    }
}

int main()
{
    // Build Tree using postFix notation :
    char *Exp = "ABC*+D/";
    int size = strlen(Exp);

    root = CreateExpresionTree(Exp, size);

    printf("\nIn-fix order of Expretion is : ");
    InOrderTrav(root);

    return 0;
}