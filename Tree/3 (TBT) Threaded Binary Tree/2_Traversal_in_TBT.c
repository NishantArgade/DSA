#include <stdio.h>
#include <stdlib.h>

struct TBT *root = NULL;
//===========================     Creation of Queue    ================================================================================================================================
// Treaded binary tree (TBT);
struct TBT
{
    struct TBT *Lchild;
    int Lflag;
    int data;
    int Rflag;
    struct TBT *Rchild;
};
struct TBT *insertinTBT(struct TBT *head, struct TBT *temp)
{
    struct TBT *ptr = head->Lchild;
    struct TBT *parent = NULL;
    while (ptr != NULL)
    {
        parent = ptr;
        if (temp->data < ptr->data)
        {
            if (ptr->Lflag == 1)

                ptr = ptr->Lchild;

            else
                break;
        }

        else
        {
            if (ptr->Rflag == 1)

                ptr = ptr->Rchild;

            else
                break;
        }
    }

    if (temp->data < parent->data)
    {
        parent->Lchild = temp;
        temp->Lchild = parent->Lchild;
        temp->Rchild = parent;
        parent->Lflag = 1;
    }
    if (temp->data > parent->data)
    {
        parent->Rchild = temp;
        temp->Rchild = parent->Rchild;
        temp->Lchild = parent;
        parent->Rflag = 1;
    }
    return head;
}
struct TBT *CreateTBTree(struct TBT *root, struct TBT *head)
{
    int i = 0, k;
    printf("Enter number of nodes you want to inserted : ");
    scanf("%d", &k);

    while (i < k)
    {
        struct TBT *temp = (struct TBT *)malloc(sizeof(struct TBT));
        int data;

        printf("Enter new node data : ");
        scanf("%d", &data);
        temp->data = data;
        temp->Lchild = temp->Rchild = NULL;
        temp->Lflag = temp->Rflag = 0;

        if (root == NULL)
        {
            root = temp;

            head->data = 999;
            head->Lchild = root;
            head->Rchild = head;
            head->Lflag = head->Rflag = 1;
            root->Lchild = head;
            root->Rchild = head;
        }
        else
            head = insertinTBT(head, temp);

        i++;
    }
    return head;
}
struct TBT *leftmostNode(struct TBT *ptr)
{
    while (ptr->Rflag == 1)
    {
        ptr = ptr->Rchild;
    }
    return ptr;
}
struct TBT *rightmostNode(struct TBT *ptr)
{
    while (ptr->Rflag == 1)
    {
        ptr = ptr->Rchild;
    }
    return ptr;
}
struct TBT *preorderSuccessorininorderBt(struct TBT *ptr)
{
    if (ptr->Lflag == 1)
    {
        return ptr->Lchild;
    }
    else
    {
        while (ptr->Rflag == 0)
        {
            ptr = ptr->Rchild;
        }
        ptr = ptr->Rchild;
        return ptr;
    }
}

void inOrder(struct TBT *root)
{
    struct TBT *t = root;
    struct TBT *lastNode = rightmostNode(root);
    while (1)
    {
        while (t->Lflag == 1)
        {
            t = t->Lchild;
        }

        printf(" %d ", t->data);
        while (t->Rflag == 0)
        {
            if (t == lastNode)
            {
                return;
            }
            t = t->Rchild;
            printf(" %d ", t->data);
        }
        t = t->Rchild;
    }
}
void preOrdertrav(struct TBT *head)
{
    struct TBT *p = head;
    while (1)
    {
        p = preorderSuccessorininorderBt(p);
        if(p == head)
          return;                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        printf(" %d ", p->data);
    }
}
void preOrder(struct TBT *root)
{
    struct TBT *t = root;
    // struct TBT *lmostNode = lastNode(root);
    struct TBT *lastNode = rightmostNode(root);
    while (1)
    {
        while (t->Lflag == 1)
        {
            printf(" %d ", t->data);
            t = t->Lchild;
        }
        printf(" %d ", t->data);

        while (t->Rflag == 0)
        {
            if (t == lastNode)
            {
                return;
            }
            t = t->Rchild;
            // printf(" %d ", t->data);
        }
        t = t->Rchild;
    }
}

// void postOrder(struct TBT *root)
// {
//     struct TBT *t = root;
//     // struct TBT *lmostNode = lastNode(root);
//     struct TBT *lastNode = rightmostNode(root);
//     while (1)
//     {
//         while (t->Lflag == 1)
//         {
//             printf(" %d ", t->data);
//             t = t->Lchild;
//         }
//         printf(" %d ", t->data);
//         while (t->Rflag == 0)
//         {
//             if (t == lastNode)
//             {
//                 return;
//             }
//             t = t->Rchild;
//             // printf(" %d ", t->data);
//         }
//         t = t->Rchild;
//     }
// }

int main()
{
    // create dummy node(head) :
    struct TBT *head = (struct TBT *)malloc(sizeof(struct TBT));
    head = CreateTBTree(root, head);
    root = head->Lchild;

    // Stackless or queueless traversal using Threaded binary tree:

    // printf("\ninOreder Traversal  of Threaded binary tree is :");
    // inOrder(root);
    // printf("\nPreOreder Traversal of Threaded binary tree is :");
    // preOrder(root);

    //i couldn't code this  printf("\nPostOreder Traversal of Threaded binary tree is :");
    // postOrder(root);
    preOrdertrav(head);

    return 0;
}
