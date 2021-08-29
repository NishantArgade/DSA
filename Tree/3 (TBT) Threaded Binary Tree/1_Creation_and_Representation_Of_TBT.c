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
struct TBT *insertinTBT(struct TBT *root, struct TBT *temp)
{
    struct TBT *ptr = root;
    struct TBT *par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
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

    if (temp->data < par->data)
    {
        par->Lchild = temp;
        temp->Lchild = par->Lchild;
        temp->Rchild = par;
        par->Lflag = 1;
    }
    if (temp->data > par->data)
    {
        par->Rchild = temp;
        temp->Rchild = par->Rchild;
        temp->Lchild = par;
        par->Rflag = 1;
    }
    return root;
}
struct TBT *CreateTBTree(struct TBT *root,struct TBT *dummyN)
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

            
            dummyN->data = 999;
            dummyN->Lchild = root;
            dummyN->Rchild = dummyN;
            dummyN->Lflag = dummyN->Rflag = 1;
            root->Lchild = dummyN;
            root->Rchild = dummyN;
        }
        else
            root = insertinTBT(root, temp);

        i++;
    }
    return dummyN;
}

int main()
{
   struct TBT *dummyN = (struct TBT *)malloc(sizeof(struct TBT));
    struct TBT *newroot = CreateTBTree(root,dummyN);

    printf(" %d ", newroot->data);
    printf(" %d ", newroot->Lchild->data);
    printf(" %d ", newroot->Lchild->Lchild->data);
    // printf(" %d ", newroot->Rchild->Rchild->data);

    return 0;
}
