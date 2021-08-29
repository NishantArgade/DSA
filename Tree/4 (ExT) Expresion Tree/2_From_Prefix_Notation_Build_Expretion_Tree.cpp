#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct BTNode *root = NULL;
struct BTNode *temp = NULL;

struct BTNode
{
    char data;
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
void postOrderTrav(struct BTNode *root)
{
    if (!root)
    {
        return;
    }
    postOrderTrav(root->Lchild);
    postOrderTrav(root->Rchild);
    cout << root->data << " ";
    // cout << endl;
}
int isOperator(char ope)
{
    if (ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '%')
        return 1;
    else
        return 0;
}
struct BTNode *CreateExpresionTree(string Exp, int &curr)
{
    if (curr <= 0)
    {
        return NULL;
    }

    struct BTNode *root = (struct BTNode *)malloc(sizeof(struct BTNode));
    root->data = Exp[curr];
    root->Lchild = root->Rchild = NULL;

    curr--;

    if (isOperator(Exp[curr]))
    {
        root->Rchild = CreateExpresionTree(Exp, curr);
        root->Lchild = CreateExpresionTree(Exp, curr);
    }
    return root;
}
int main()
{
    string Exp = "ab*cd-+";
    int size = 7;

    root = CreateExpresionTree(Exp, size);
    
    cout<< Exp[0]<<" ";     // <=== try and hadling .

    // levelOrderTrav(root);
    postOrderTrav(root);

    
    return 0;
}
