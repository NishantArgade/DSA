#include <iostream>
#include <map>
#include <queue>
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

void Top_View_BT(BTNode *root, queue<pair<BTNode *, int>> &q, map<int, int> &mp, int hd)
{
    if (!root)
        return;

    q.push(make_pair(root, hd));
    while (!q.empty())
    {
        pair<BTNode *, int> p = q.front();
        q.pop();

        BTNode *temp = p.first;
        hd = p.second;

        if (mp.find(hd) == mp.end())
            mp[hd] = temp->data;

        if (temp->Lchild)
            q.push(make_pair(temp->Lchild, hd - 1));
        if (temp->Rchild)
            q.push(make_pair(temp->Rchild, hd + 1));
    }
}
void Bottom_View_BT(BTNode *root, queue<pair<BTNode *, int>> &q2, map<int, int> &mp2, int hd)
{
    if (!root)
        return;

    q2.push(make_pair(root, hd));
    while (!q2.empty())
    {
        pair<BTNode *, int> p = q2.front();
        q2.pop();

        BTNode *temp = p.first;
        hd = p.second;

        mp2[hd] = temp->data;

        if (temp->Lchild)
            q2.push(make_pair(temp->Lchild, hd - 1));
        if (temp->Rchild)
            q2.push(make_pair(temp->Rchild, hd + 1));
    }
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

//====================== TOP View ================================================
    map<int, int> mp;
    queue<pair<BTNode *, int>> q;

    Top_View_BT(root, q, mp, 0);

    cout << "The Top View of Binary Tree is :" << endl;
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout <<" "<<it->second << " ";
    }
//====================== BOTTOM View ==============================================
    map<int, int> mp2;
    queue<pair<BTNode *, int>> q2;

    Bottom_View_BT(root, q2, mp2, 0);

    cout << "\nThe Bottom View of Binary Tree is :" << endl;

    for (it = mp2.begin(); it != mp2.end(); it++)
    {
        cout <<" "<< it->second << " ";
    }

    return 0;
}