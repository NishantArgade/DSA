#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// set global pointers:
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root1;
struct BTNode *root2;

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

// Create TWO Binary Tree :
void CreateTree1()
{
    // Create a Queue for storing node address
    struct Queue q;
    CreateQueue(&q, 100);

    // create roo1t node
    // initialy queue is empty
    if (isEmpty(f))
    {
        int data;
        printf("Enter roo1t node Data :\n");
        scanf("%d", &data);
        root1 = (struct BTNode *)malloc(sizeof(struct BTNode));
        root1->data = data;
        root1->Lchild = root1->Rchild = NULL;
        enqueue(root1);
    }

    // create new nodes
    // after push roo1t node is not empty
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
void CreateTree2()
{
    // Create a Queue for storing node address
    struct Queue q;
    CreateQueue(&q, 100);

    // create root2 node
    // initialy queue is empty
    if (isEmpty(f))
    {
        int data;
        printf("Enter root2 node Data :\n");
        scanf("%d", &data);
        root2 = (struct BTNode *)malloc(sizeof(struct BTNode));
        root2->data = data;
        root2->Lchild = root2->Rchild = NULL;
        enqueue(root2);
    }

    // create new nodes
    // after push roo1t node is not empty
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
    printf("\n");
}

int arestructuralyIdenticalTrees(struct BTNode *root1, struct BTNode *root2)
{

    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;

    if (root1->data == root2->data){
        arestructuralyIdenticalTrees(root1->Lchild, root2->Lchild);
        arestructuralyIdenticalTrees(root1->Rchild, root2->Rchild);  
    }
    else
      return 0;
   
}
int AreMirrors(struct BTNode *root1,struct BTNode* root2)
{
   if(root1==NULL && root2 == NULL)
     return 1;
    if(root1==NULL || root2 == NULL)
      return 0;
    if(root1->data != root2->data )
      return 0;
      
    else
      (AreMirrors(root1->Lchild,root2->Rchild) && AreMirrors(root1->Rchild,root2->Lchild));
  
}
int main()
{

    printf("Create First Tree :\n");
    CreateTree1();
   
    printf("Create second Tree :\n");
    CreateTree2();

    printf("iterative : Level-Order Traversal for tree1 and tree2 is :\n");
    levelOrderTrav(root1);
    levelOrderTrav(root2);

    printf("Are structuraly identical ? : %d ", arestructuralyIdenticalTrees(root1, root2));
    printf("\nThe MirrorofTree is Exists or not ? : %d ",AreMirrors(root1,root2));


    return 0;
}
