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
void inOrder(BSTnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    cout << root->data << " ";
    inOrder(root->Rchild);
}

int Elements_for_target(BSTnode *root, int target)
{
    stack<BSTnode *> s1; // For Store Lower element.
    stack<BSTnode *> s2; // For Store Greater element.
    BSTnode *x, *y, *temp, *temp2, *t1, *t2;
    t1 = root;
    t2 = root;
    while (t1)
    {
        s1.push(t1);
        t1 = t1->Lchild;
    }
    while (t2)
    {
        s2.push(t2);
        t2 = t2->Rchild;
    }
    while (1)
    {

        x = s1.top();
        y = s2.top();

        if (x->data + y->data == target)
        {
            cout << "\nElements for which sum is equal to target is : " << endl;
            cout << x->data << " " << y->data;
            return 1;
        }
        if (x->data + y->data < target)
        {
            temp = s1.top();
            s1.pop();
            temp = temp->Rchild;

            if (temp)
                s1.push(temp);
        }
        else if (x->data + y->data > target)
        {
            temp = s2.top();
            s2.pop();
            temp = temp->Lchild;

            if (temp)
                s2.push(temp);
        }
        if (s1.empty())
        {
            break;
        }
        if (s2.empty())
        {
            break;
        }
    }
    return 0;
}
int main()
{
    root = Re_insertion(root, 10);
    root = Re_insertion(root, 8);
    root = Re_insertion(root, 15);
    root = Re_insertion(root, 6);
    root = Re_insertion(root, 9);
    root = Re_insertion(root, 12);
    root = Re_insertion(root, 25);
    root = Re_insertion(root, 11);
    root = Re_insertion(root, 13);
    inOrder(root);

    Elements_for_target(root, 27);
    return 0;
}
