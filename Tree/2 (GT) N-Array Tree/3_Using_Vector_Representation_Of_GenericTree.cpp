
//3. Way to represent N- Ary Tree(Generic Tree )(Recomended ):

#include <iostream>
#include <vector>

using namespace std;

struct GTNode *root, *Cnode, *Snode;

 // ( Generic Tree )N-Ary Tree Node:
struct GTNode
{
    int data;
    vector<struct GTNode *> Child;
};
struct GTNode *CreateNewNode(int data)
{
    root = new GTNode;
    root->data = data;
    root->Child.push_back(NULL);

    return root;
}
int main()
{
    // Create N- Ary Tree :

    struct GTNode *root = CreateNewNode(0);

    root->Child[0] = CreateNewNode(1);
    root->Child[1] = CreateNewNode(2);
    root->Child[2] = CreateNewNode(3);

    root->Child[0]->Child[0] = CreateNewNode(4);
    root->Child[0]->Child[1] = CreateNewNode(5);
    root->Child[0]->Child[2] = CreateNewNode(6);

    root->Child[1]->Child[0] = CreateNewNode(7);
    root->Child[1]->Child[1] = CreateNewNode(8);
    root->Child[1]->Child[2] = CreateNewNode(9);
    root->Child[1]->Child[3] = CreateNewNode(10);

    // Dispaly N ary Tree: 

    cout << root->data << " ";

    cout << root->Child[0]->data << " ";
    cout << root->Child[1]->data << " ";
    cout << root->Child[2]->data << " ";

    cout << root->Child[0]->Child[0]->data << " ";
    cout << root->Child[0]->Child[1]->data << " ";
    cout << root->Child[0]->Child[2]->data << " ";

    cout << root->Child[1]->Child[0]->data << " ";
    cout << root->Child[1]->Child[1]->data << " ";
    cout << root->Child[1]->Child[2]->data << " ";
    cout << root->Child[1]->Child[3]->data << " ";

    return 0;
}