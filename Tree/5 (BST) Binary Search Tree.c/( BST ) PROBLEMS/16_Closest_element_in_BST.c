// Representation of binary search tree :

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct BSTnode *root = NULL;
struct BSTnode *temp;
struct BSTnode *q = NULL;

struct BSTnode
{
    int data;
    struct BSTnode *Lchild;
    struct BSTnode *Rchild;
};

struct BSTnode *Re_Insertion_and_creation_BST(struct BSTnode *root, int data)
{
    if (root == NULL)
    {
        struct BSTnode *root = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        root->data = data;
        root->Lchild = root->Rchild = NULL;

        return root;
    }
    else
    {
        if (data < root->data)
            root->Lchild = Re_Insertion_and_creation_BST(root->Lchild, data);

        else if (data > root->data)
            root->Rchild = Re_Insertion_and_creation_BST(root->Rchild, data);
    }
    return root;
}

int Re_InOrderTrav(struct BSTnode *root)
{
    if (root)
    {
        Re_InOrderTrav(root->Lchild); //   1.goto left
        printf(" %d ", root->data);   //  2.goto root
        Re_InOrderTrav(root->Rchild); //   3.goto Right
    }
}

int closest_element(struct BSTnode *root, int val)
{
    if (!root)
        return 0;

    int CurrDiff, minDiff = INT_MAX, closest_ele;

    while (root != NULL)
    {
        CurrDiff = (root->data - val);

        if (CurrDiff < 0)
            CurrDiff = -CurrDiff;

        if (CurrDiff < minDiff)
        {
            minDiff = CurrDiff;
            closest_ele = root->data;
        }

        if (val < root->data)
            root = root->Lchild;

        else if (root->data < val)
            root = root->Rchild;

        else if (minDiff == CurrDiff)
            break;
    }
    return closest_ele;
}

int main()
{

    root = Re_Insertion_and_creation_BST(root, 10);
    root = Re_Insertion_and_creation_BST(root, 8);
    root = Re_Insertion_and_creation_BST(root, 15);
    root = Re_Insertion_and_creation_BST(root, 6);
    root = Re_Insertion_and_creation_BST(root, 9);
    root = Re_Insertion_and_creation_BST(root, 12);
    root = Re_Insertion_and_creation_BST(root, 25);

    // Re_InOrderTrav(root);
    int val = 18  ;
    int ans = closest_element(root, val);
    printf("The closest element of %d  is %d\n", val, ans);
}
