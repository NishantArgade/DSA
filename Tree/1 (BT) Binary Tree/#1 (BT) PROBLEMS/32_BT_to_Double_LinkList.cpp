#include <iostream>
#include <queue>

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
        cout << root->data <<" ";
        q.push(root);
    }
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->Lchild)
        {
            cout << root->Lchild->data<<" ";
            q.push(root->Lchild);
        }
        if (root->Rchild)
        {
            cout << root->Rchild->data<<" ";
            q.push(root->Rchild);
        }
    }
    cout << endl;
}

void BTtoDLL(struct BTNode *root, struct BTNode *&head, struct BTNode *&tail)
{
    if (!root)
        return;

    BTtoDLL(root->Lchild, head, tail);

    if (!head)
    {
        head = root;
    }

    else
    {
        root->Lchild = tail;
        tail->Rchild = root;
    }
    tail = root;

    BTtoDLL(root->Rchild, head, tail);
}
void Double_linkList_Traversal(struct BTNode *head, struct BTNode *tail)
{
    printf("The Double Link List Structure is :\n");
    struct BTNode *p = head;
    do
    {
        cout << p->data << " ";
        p = p->Rchild;
    } while (p != NULL); // if first condition false however run loop at Once
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

    BTtoDLL(root, head, tail);
    Double_linkList_Traversal(head, tail);

    return 0;
}
