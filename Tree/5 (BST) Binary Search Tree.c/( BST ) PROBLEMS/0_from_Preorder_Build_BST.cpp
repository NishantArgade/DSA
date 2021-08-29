#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct BSTnode *curr;
struct BSTnode *q = NULL;

struct BSTnode
{
    int data;
    BSTnode *Lchild, *Rchild;
} *root = NULL;
void inOrder(BSTnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    cout << root->data << " ";
    inOrder(root->Rchild);
}

BSTnode *CreateBST_from_LevelOrder(vector<int> levelOrder)
{
    if (levelOrder.size() == 0) // When no Node exists
        return NULL;
    
    struct BSTnode *root = new BSTnode;
    root->data = levelOrder[0];

    vector<int> Lvec, Rvec;
    for (int i = 1; i < levelOrder.size(); i++)
    {
        if (levelOrder[i] < root->data)
            Lvec.push_back(levelOrder[i]);

        if (levelOrder[i] > root->data)
            Rvec.push_back(levelOrder[i]);
    }
    root->Lchild = CreateBST_from_LevelOrder(Lvec);
    root->Rchild = CreateBST_from_LevelOrder(Rvec);

    return root;
}
int main()
{
    //  Creation Of BST From  PreOrder :

    vector<int> levelOrder = {10, 5, 15, 2, 6};

    root = CreateBST_from_LevelOrder(levelOrder);

    cout << "\nAfter Creation Of BST From  CraeteBST_from_levelOrder function traversal is :\n";
    inOrder(root);

    return 0;
}