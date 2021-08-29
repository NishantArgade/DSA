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
} *root = NULL, *root1 = NULL, *root2 = NULL;

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

void inOrderandpushStack(BSTnode *root, stack<BSTnode *> &s)
{
    if (!root)
        return;
    inOrderandpushStack(root->Rchild, s); //***
    s.push(root);
    inOrderandpushStack(root->Lchild, s); //***
}

int All_element_2_BST(BSTnode *root1, BSTnode *root2)
{
    stack<BSTnode *> s1; // For Store Lower element.
    stack<BSTnode *> s2; // For Store Greater element.
    BSTnode *x, *y, *temp, *temp2, *t1, *t2;

    inOrderandpushStack(root1, s1);
    inOrderandpushStack(root2, s2);

    while (1)
    {

        x = s1.top();
        y = s2.top();

        if (x->data == y->data)
        {
            temp = s1.top();
            s1.pop();
            s2.pop();
            cout << temp->data << " " << temp->data;
        }
        if (x->data < y->data)
        {
            temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
        }
        else
        {
            temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
        }
        if (s1.empty() || s2.empty())
            break;
    }

    while (!s2.empty())
    {
        temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }

    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        cout << temp->data << " ";
    }
    return 0;
}

int main()
{
    cout << "First Tree :\n";
    root1 = Re_insertion(root1, 10);
    root1 = Re_insertion(root1, 8);
    root1 = Re_insertion(root1, 15);
    root1 = Re_insertion(root1, 60);
    root1 = Re_insertion(root1, 9);

    inOrder(root1);

    cout << "\nSecond Tree :\n";
    root2 = Re_insertion(root2, 7);
    root2 = Re_insertion(root2, 5);
    root2 = Re_insertion(root2, 2);
    root2 = Re_insertion(root2, 3);
    root2 = Re_insertion(root2, 70);

    inOrder(root2);

    cout << "\nAll Element of Two Binary Tree in Sorted Order is : " << endl;
    All_element_2_BST(root1, root2);
    return 0;
}
