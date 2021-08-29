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

void Digonal_Traversal_BT(BTNode *root, map<int, vector<int>> &mp, int hd)
{
    if (!root)
        return;
    mp[hd].push_back(root->data);

    Digonal_Traversal_BT(root->Lchild, mp, hd + 1);
    Digonal_Traversal_BT(root->Rchild, mp, hd);
}

int main()
{
    struct BTNode *root = CreateNewNode(50);
    root->Lchild = CreateNewNode(40);
    root->Rchild = CreateNewNode(60);
    root->Lchild->Lchild = CreateNewNode(30);
    root->Lchild->Rchild = CreateNewNode(45);
    root->Rchild->Lchild = CreateNewNode(35);
    root->Rchild->Rchild = CreateNewNode(70);

    //======================Digonal Traversal================================================

    map<int, vector<int>> mp;

    Digonal_Traversal_BT(root, mp, 0);

    cout << "The Digonal Traversal of Binary Tree is :" << endl;
    map<int, vector<int>>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << " " << it->second[i] << " ";
            
        }
        cout<<endl;
    }

    return 0;
}