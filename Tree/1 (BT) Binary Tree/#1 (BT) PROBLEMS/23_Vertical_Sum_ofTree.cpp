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

void getVerticalTraversal(struct BTNode *root, int column, map<int,int> &mp)
{
    if (root == NULL)
        return;

    mp[column] = mp[column]+ (root->data);

    getVerticalTraversal(root->Lchild, column - 1, mp);
    getVerticalTraversal(root->Rchild, column + 1, mp);
}
void printVerticalTraversal(struct BTNode *root)
{
    map<int, int> mp;
    int column = 0;
    getVerticalTraversal(root, column, mp);

    map<int,int>::iterator itr;

    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->second << " ";
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
    
    cout<<"Verticaly sum is : "<<endl;
    printVerticalTraversal(root);
    return 0;
}