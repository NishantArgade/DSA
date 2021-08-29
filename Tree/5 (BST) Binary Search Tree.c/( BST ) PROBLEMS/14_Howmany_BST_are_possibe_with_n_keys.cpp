#include <iostream>
#include <climits>
#include <vector>
using namespace std;

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

int possible_BST_for_n_Keys(int n)
{
    if (n == 0 || n == 1)// n= 0 i.e NULL tree,so that  possible BST is 1
        return 1;

    int sum = 0, left, right;
    for (int i = 0; i < n; i++)// for each root calculate possible BST
    {
        left = possible_BST_for_n_Keys(i);// Possible BST on Left side
        right = possible_BST_for_n_Keys(n - i - 1);//Possible BST on Right Side.
        sum = sum + left * right;// Total Possibility
    }
    return sum;// return each root's possibility.
}

int main()
{

    int Arr[] = {10, 25, 50}; // ele will be change

    int possibility,n;

    n = sizeof(Arr) / sizeof(Arr[0]);
    possibility = possible_BST_for_n_Keys(n);

    cout << "The Possible  BST will be that store " << n << " keys is : " << endl;
    cout << possibility;
    return 0;
}
