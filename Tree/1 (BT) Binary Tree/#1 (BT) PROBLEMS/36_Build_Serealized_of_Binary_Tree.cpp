#include <iostream>
#include <queue>
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
void levelOrderTrav(struct BTNode *root)
{
    queue<BTNode *> q;
    if (q.empty())
    {
        cout << root->data << " ";
        q.push(root);
    }
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->Lchild)
        {
            cout << root->Lchild->data << " ";
            q.push(root->Lchild);
        }
        if (root->Rchild)
        {
            cout << root->Rchild->data << " ";
            q.push(root->Rchild);
        }
    }
    cout << endl;
}
void preOrderTrav(struct BTNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTrav(root->Lchild);
    preOrderTrav(root->Rchild);
    // cout << endl;
}

void Build_Serealized_BT(BTNode *root, vector<int> &vec)
{
    if (!root)
    {
        vec.push_back(-1);
        return;
    }
    vec.push_back(root->data);

    Build_Serealized_BT(root->Lchild, vec);
    Build_Serealized_BT(root->Rchild, vec);
}
BTNode *Build_DeSerealized_BT(vector<int> &vec, int &i)
{
    if (vec[i] == -1)
    {
        i++;
        return NULL; 
    }

    BTNode *newNode = new BTNode;
    newNode->data = vec[i];
    newNode->Lchild = newNode->Rchild = NULL;

    i++;
    newNode->Lchild = Build_DeSerealized_BT(vec, i);
    newNode->Rchild = Build_DeSerealized_BT(vec, i);

    return newNode;
}

int main()
{
    struct BTNode *root = CreateNewNode(1);
    root->Lchild = CreateNewNode(2);
    root->Rchild = CreateNewNode(3);
    root->Lchild->Lchild = CreateNewNode(4);
    root->Lchild->Rchild = CreateNewNode(5);
    root->Rchild->Lchild = CreateNewNode(6);
    root->Rchild->Rchild = CreateNewNode(7);

    // Serealization of BT:

    vector<int> vec ;
    Build_Serealized_BT(root, vec);

cout<<"Serealization of Binary Tree is :\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

//=================================================================================================
    // DeSerealization of BT:

    int i = 0;
    root = Build_DeSerealized_BT(vec, i);
    
cout<<"\nDeSerealization of Binary Tree is :\n";
    preOrderTrav(root);

    return 0;
}