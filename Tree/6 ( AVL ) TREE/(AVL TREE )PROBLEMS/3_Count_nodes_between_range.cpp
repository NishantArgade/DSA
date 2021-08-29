#include <iostream>
#include <climits>
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
// int count = 0;
void rangePrint(BSTnode *root, int K1, int K2,int &count)
{
    if (!root)
        return;

    if (root->key >= K1)
        rangePrint(root->Lchild, K1, K2,count);

    if (root->key >= K1 && root->key <= K2)
        // cout << root->key << " ";
        count++;

    if (root->key <= K2)
        rangePrint(root->Rchild, K1, K2,count);

}

int main()
{
    root = Re_insertion(root, 7);
    root = Re_insertion(root, 5);
    root = Re_insertion(root, 2);
    root = Re_insertion(root, 6);
    root = Re_insertion(root, 30);
    inOrder(root);

    int K1, K2,count =0;
    cout << "\nEnter K1 and K2 : " << endl;
    cin >> K1 >> K2;
    rangePrint(root, K1, K2,count);
    cout << "The element Between Range K1 and K2 is : " <<count<< endl;
     
    
    return 0;
}