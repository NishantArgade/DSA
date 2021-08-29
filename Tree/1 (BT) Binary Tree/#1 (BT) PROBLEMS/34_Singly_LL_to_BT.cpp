#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

struct BTNode *root = NULL;
struct BTNode *head = NULL;
struct BTNode *tail = NULL;
struct BTNode
{
    int data;
    struct BTNode *Lchild;
    struct BTNode *Rchild;
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
struct BTNode *SinglyLLtoBT(vector<BTNode *> vec)
{

    int n = vec.size();
    int i = 0;
    while (1)
    {
        if (i == n)
            return vec[0];

        int Fchild = 2 * i + 1;
        int Schild = 2 * i + 2;

        if (Fchild < n && Schild < n)
        {
            vec[i]->Lchild = vec[Fchild];
            vec[i]->Rchild = vec[Schild];
        }
        else
        {

            if (Fchild < n)
                vec[i]->Lchild = vec[Fchild];

            if (Schild < n)
                vec[i]->Rchild = vec[Schild];
        }
        i++;
    }
}

int main()
{   // Given singly Link List:

    list<int> LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);
    LL.push_back(4);
    LL.push_back(5);

    //1. Create new nodes from singly LinkList and push into the vector:
    vector<BTNode *> vec;
    while (!LL.empty())
    {
        BTNode *newnode = new BTNode;
        newnode->data = LL.front();
        newnode->Lchild = newnode->Rchild = NULL;

        vec.push_back(newnode);
        LL.pop_front();
    }

    //2. After pushing all Nodes Build BT :
    root = SinglyLLtoBT(vec);

    //3. Printing all nodes of newly Created binary tree:
    cout << "Level Order Traversal of Newly Craeted BT from LL is\n";
    levelOrderTrav(root);

    return 0;
}
