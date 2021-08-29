#include <iostream>
using namespace std;

// struct BSTnode *root = NULL;
struct BSTnode *curr;
struct BSTnode *q = NULL;

struct BSTnode
{
    int key;
    BSTnode *Lchild, *Rchild;
} *root = NULL;
BSTnode *Re_insertion(BSTnode *root, int data)
{
    struct BSTnode *NewNode, *p = root;
    if (p == NULL)
    {
        NewNode = new BSTnode;
        NewNode->key = data;
        NewNode->Lchild = NewNode->Rchild = NULL;
        p = NewNode;
        return p;
    }
    else
    {
        if (data < p->key)
            p->Lchild = Re_insertion(p->Lchild, data);
        else if (data > p->key)
            p->Rchild = Re_insertion(p->Rchild, data);
    }
    return p;
}
void inOrder(BSTnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    cout << root->key << " ";
    inOrder(root->Rchild);
}

void Kth_largest_Number(struct BSTnode *root, int &K1, int &val1)
{
    if (!root)
        return;
    if (K1 <= 0)
        return;
    Kth_largest_Number(root->Rchild, K1, val1); //**************

    K1--;
    if (K1 == 0)
    {
        val1 = root->key;
        return;
    }
    Kth_largest_Number(root->Lchild, K1, val1); //**************
}
void Kth_smallest_Number(struct BSTnode *root, int &K, int &val)
{
    if (!root)
        return;
    if (K <= 0)
        return;
    Kth_smallest_Number(root->Lchild, K, val);

    K--;
    if (K == 0)
    {
        val = root->key;
        return;
    }
    Kth_smallest_Number(root->Rchild, K, val);
}

int main()
{
    root = Re_insertion(root, 10);
    root = Re_insertion(root, 20);
    root = Re_insertion(root, 30);
    root = Re_insertion(root, 5);
    root = Re_insertion(root, 40);
    inOrder(root);

    // (inorder) L->Node->R takes increasing Order of Element ,using this idea we can get Kth smallest Element .
    int K1, val1;
    cout << "\nFor Finding K1 th Largest Element,Enter K1 : ";
    cin >> K1;
    Kth_largest_Number(root, K1, val1);
    cout << val1;

    // (inorder) R->Node->L takes decreasing Order of Element ,using this idea we can get Kth largest Element .
    int K, val;
    cout << "\nFor Finding K th Smallest Element,Enter K : ";
    cin >> K;
    Kth_smallest_Number(root, K, val);
    cout << val;

    return 0;
}