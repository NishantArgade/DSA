#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct BTNode *root = NULL;
struct BTNode *temp = NULL;

struct BTNode
{
    int data;
    struct BTNode *Lchild;
    struct BTNode *Rchild;
};
struct BTNode *CreateNewNode(int data)
{
    // Dinamicaly Allocate Memory :
    struct BTNode *root = new BTNode;

    root->data = data;
    root->Lchild = root->Rchild = NULL;

    return root;
}

void Left_Boundary(BTNode *root, vector<int> &vec)
{
    if (!root)
        return;

    if (root->Lchild || root->Rchild)
        vec.push_back(root->data);

    Left_Boundary(root->Lchild, vec);
    Left_Boundary(root->Rchild, vec);
}
void Leaf_Boundary(BTNode *root, vector<int> &vec)
{
    if (!root)
        return;

    Leaf_Boundary(root->Lchild, vec);
    Leaf_Boundary(root->Rchild, vec);

    if (root->Lchild == NULL && root->Rchild == NULL)
        vec.push_back(root->data);
}
void Right_Boundary(BTNode *root, vector<int> &vec)
{
    if (!root)
        return;

    Right_Boundary(root->Rchild, vec);
    Right_Boundary(root->Lchild, vec);

    if (root->Lchild || root->Rchild)
        vec.push_back(root->data);
}
vector<int> Boundary_Traversal_BT(BTNode *root)
{
    vector<int> vec;
    vec.push_back(root->data);

    if (!root)
        return vec;

    if (!root->Lchild && !root->Rchild)
        return vec;

    Left_Boundary(root->Lchild, vec);
    Leaf_Boundary(root, vec);
    Right_Boundary(root->Rchild, vec);

    return vec;
}

int main()
{
    struct BTNode *root = CreateNewNode(1);
    root->Lchild = CreateNewNode(2);
    root->Rchild = CreateNewNode(5);
    root->Lchild->Rchild = CreateNewNode(3);
    root->Lchild->Rchild->Lchild = CreateNewNode(4);
    root->Rchild->Lchild = CreateNewNode(8);
    root->Rchild->Rchild = CreateNewNode(6);
    root->Rchild->Rchild->Lchild = CreateNewNode(7);
    root->Rchild->Rchild->Lchild ->Lchild = CreateNewNode(9);


    //======================Boundary Traversal================================================

    vector<int> tvec = Boundary_Traversal_BT(root);

    cout << "The Boundary Traversal of Binary Tree is :" << endl;

    for (int i = 0; i < tvec.size(); i++)
    {
        cout << tvec[i] << " ";
    }

    return 0;
}