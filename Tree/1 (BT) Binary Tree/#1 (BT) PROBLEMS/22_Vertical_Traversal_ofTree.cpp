#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct BTNode
{
    int data;
    struct BTNode *Lchild, *Rchild;
};
struct BTNode *CreateNewNode(int data)
{
    // Dinamicaly Allocate Memory :
    struct BTNode *root = new BTNode;

    root->data = data;
    root->Lchild = root->Rchild = NULL;

    return root;
}

void getVerticalTraversal(struct BTNode *root, int column, map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;

    mp[column].push_back(root->data);

    getVerticalTraversal(root->Lchild, column - 1, mp);
    getVerticalTraversal(root->Rchild, column + 1, mp);
}
void printVerticalTraversal(struct BTNode *root)
{
    map<int, vector<int>> mp;
    int column = 0;
    getVerticalTraversal(root, column, mp);

    map<int, vector<int>>::iterator itr;

    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        for (int i = 0; i < itr->second.size(); ++i)
        {
            cout << itr->second[i] << " ";
        }
        cout << endl;
    }
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

    cout << "Verticaly Traversal is : " << endl;
    printVerticalTraversal(root);
    return 0;
}