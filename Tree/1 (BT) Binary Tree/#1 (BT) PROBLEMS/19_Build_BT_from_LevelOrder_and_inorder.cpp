#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Create Queue :
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;
struct BTNode *root;

struct BTNode
{
    int data;
    struct BTNode *Lchild, *Rchild;
};
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

int getinorderind(vector<int> IO, int data)
{
    for (int i = 0; i < IO.size(); i++)
    {
        if (IO[i] == data)
        {
            return i;
        }
    }
}
vector<int> FindLevelOrderEle(vector<int> IO, int inStart, int inEnd, vector<int> LO)
{
    vector<int> tvec;

    for (int i = 0; i < LO.size(); i++)
    {

        for (int j = inStart; j < inEnd; j++)
        {
            if (LO[i] == IO[j])
            {
                tvec.push_back(LO[i]);
            }
        }
    }
    return tvec;
}
vector<int> GetIOEle(vector<int> IO, int inStart, int inEnd)
{
    vector<int> tvec;

    for (int j = inStart; j < inEnd; j++)
    {

        tvec.push_back(IO[j]);
    }

    return tvec;
}

// Recursive Functions for Build Binary Tree:
struct BTNode *BuildTree(vector<int> LO, vector<int> IO)
{

    struct BTNode *newNode = new BTNode;
    newNode->data = LO[0];

    // If inStart == inEnd  i.e Only one node exists(leaf node).
    if (IO.size() == 0)
        root->Lchild = root->Rchild = NULL;
        return newNode;


    // Find root index IO inorder:
    int INind = getinorderind(IO, newNode->data);

    vector<int> forLeft_LO_Ele = FindLevelOrderEle(IO, 0, INind, LO);
    vector<int> forRight_LO_Ele = FindLevelOrderEle(IO, INind + 1, IO.size(), LO);

    vector<int> forLeft_IN_Ele = GetIOEle(LO, 0, INind);
    vector<int> forRight_IN_Ele = GetIOEle(LO, INind + 1, IO.size());

    newNode->Lchild = BuildTree(forLeft_LO_Ele, forLeft_IN_Ele);   //****
    newNode->Rchild = BuildTree(forRight_LO_Ele, forRight_IN_Ele); //****

    return newNode;
}
int main()
{
    //Build Tree using Level and inorder Traversal :

    vector<int> Level = {1, 2, 3, 4, 5, 6};
    vector<int> IO = {4, 2, 5, 1, 3, 6};

    //For post-order and IO-order: start ind = 0 and end ind = n-1  .//****
    struct BTNode *newroot = BuildTree(Level, IO);

    // queue<int> q;
    printf("New Tree Level-Order Traversal is :\n");
    levelOrderTrav(newroot);

    return 0;
}