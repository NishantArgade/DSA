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
// void inOrder(BSTnode *root)
// {
//     if (!root)
//         return;
//     inOrder(root->Lchild);
//     cout << root->data << " ";
//     inOrder(root->Rchild);
// }

void Morris_Traversal(BSTnode *root)
{
    while (root->Lchild != NULL)
    {
        BSTnode *curr = root, *temp;
        root = root->Lchild;
        temp = root;

        while (temp->Rchild != NULL)
            temp = temp->Rchild;

        temp->Rchild = curr;
        curr->Lchild = NULL;
    }
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->Rchild;
    }
}
int closest_element(struct BSTnode *root, int val, BSTnode* &closest_node,int &minDiff,int & CurrDiff)
{
    if (!root)
        return 0;



    while (root != NULL)
    {
        CurrDiff = (root->data - val);
        if(CurrDiff < 0)
             CurrDiff = - CurrDiff;
        if (CurrDiff < minDiff)
        {
            minDiff = CurrDiff;
            closest_node = root;
        }

        if (val < root->data)
            root = root->Lchild;

        else if (root->data < val)
            root = root->Rchild;
            else
            {
                
                break;
            }
            
    }
  
}
int main()
{
    root = Re_insertion(root, 10);
    root = Re_insertion(root, 8);
    root = Re_insertion(root, 15);
    root = Re_insertion(root, 20);
    root = Re_insertion(root, 6);
    root = Re_insertion(root, 9);
    root = Re_insertion(root, 3);
    root = Re_insertion(root, 7);
    root = Re_insertion(root, 2);

    // For Recursive inorder traversal TC is O(n) and space complecity is O(n);
    // inOrder(root);
    // For Morris inorder traversal TC is O(n) space complecity is O(1)***;
    // Morris_Traversal(root);// reduce space complecity => O(1)

    BSTnode* c;
    int d,m= INT_MAX;
    int ans = closest_element(root,9, c,m,d);
    cout << "closest element is %d\n"<< c->data;

    return 0;
}
