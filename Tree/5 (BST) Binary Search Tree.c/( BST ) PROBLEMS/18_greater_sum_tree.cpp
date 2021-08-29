#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

struct BSTnode *curr;
struct BSTnode *q = NULL;

struct BSTnode
{
    int data;
    BSTnode *Lchild, *Rchild;
} *root = NULL;

BSTnode *Re_insertion(BSTnode *root, int data)
{
    struct BSTnode *NewNode, *p = root;
    if (p == NULL)
    {
        NewNode = new BSTnode;
        NewNode->data = data;
        NewNode->Lchild = NewNode->Rchild = NULL;
        p = NewNode;
        return p;
    }
    else
    {
        if (data < p->data)
            p->Lchild = Re_insertion(p->Lchild, data);
        else if (data > p->data)
            p->Rchild = Re_insertion(p->Rchild, data);
    }
    return p;
}

void greater_sum_Tree(BSTnode *root, int &sum)
{
    if (!root)
        return;

    greater_sum_Tree(root->Rchild, sum); // Right Subtree

    // Proccess Node :
    sum += root->data;
    root->data = sum;
    cout << root->data << " ";

    greater_sum_Tree(root->Lchild, sum); // left subtree
}

int main()
{
    root = Re_insertion(root, 10);
    root = Re_insertion(root, 8);
    root = Re_insertion(root, 15);
    root = Re_insertion(root, 20);
    root = Re_insertion(root, 6);
    root = Re_insertion(root, 9);

    int sum = 0;
    greater_sum_Tree(root, sum);

    return 0;
}
