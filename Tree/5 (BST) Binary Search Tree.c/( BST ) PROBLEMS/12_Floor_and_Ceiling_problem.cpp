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

int Floor_Number(struct BSTnode *root, int num, int &prev)
{
    if (!root)
        return 0;
    Floor_Number(root->Lchild, num, prev);

    if (root->key == num)
    {
        prev = root->key;
        return prev;
    }
    else
    {
        if (root->key > num)
            return prev;

        prev = root->key;
    }

    return Floor_Number(root->Rchild, num, prev);
}
int Ceil_Number(struct BSTnode *root, int num, int &prev)
{
    if (!root)
        return 0;
    Ceil_Number(root->Rchild, num, prev); //***

    if (root->key == num)
        return root->key;
    else //***
    {

        if (root->key < num) //***
            return prev;
        prev = root->key;
    }

    return Ceil_Number(root->Lchild, num, prev); //***
}
void Floor_Ceil_Number(struct BSTnode *root, int num, int &Floor, int &ceil)
{
    if (!root)
        return;

    while (root)
    {
        if (num < root->key)
        {
            ceil = root->key;
            root = root->Lchild;
        }
        else if (num > root->key)
        {
            Floor = root->key;
            root = root->Rchild;
        }
        else if (num == root->key)
        {
            ceil = root->key;
            Floor = root->key;
            break;
        }
    }
}

int main()
{
    root = Re_insertion(root, 7);
    root = Re_insertion(root, 5);
    root = Re_insertion(root, 2);
    root = Re_insertion(root, 6);
    root = Re_insertion(root, 30);
    inOrder(root);

    // Floor = next Smaller element,   Ceil =  next greater element;

    int num, Floor, ceil, prev = INT_MIN;
    cout << "\nEnter Number : ";
    cin >> num;

    Floor = Floor_Number(root, num, prev);
    cout << "Floor is : " << Floor << endl;

    ceil = Ceil_Number(root, num, prev);
    cout << "ceil is : " << ceil << endl;
  
    cout <<"\nThe Floor is : " << Floor << " and ceil is : " << ceil << endl;
    Floor_Ceil_Number(root, num, Floor, ceil);

    return 0;
}