#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct BTNode *root = NULL;

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

void KthNodesinBT(BTNode *root, vector<int> &vec, int count, int k)
{
    if (!root)
        return;
    if (count == k)
        vec.push_back(root->data);

    count++;
    KthNodesinBT(root->Lchild, vec, count, k);
    KthNodesinBT(root->Rchild, vec, count, k);
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

    cout << "Level Order Traversal of given BT is\n";
    levelOrderTrav(root);

    vector<int> vec;

    cout<<"Enter K: ";
    int k;
    cin>>k;
    KthNodesinBT(root, vec, 1, k);

    cout << "K-th Nodes in BT is :\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
