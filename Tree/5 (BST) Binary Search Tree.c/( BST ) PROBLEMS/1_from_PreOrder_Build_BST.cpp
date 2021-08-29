#include <iostream>
#include <stack>
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

BSTnode *CreateBST_from_PreOrder(int pre[], int start, int end)
{

    if (start > end) // When no Node exists
        return NULL;
    
    struct BSTnode *root = new BSTnode;
    root->data = pre[start];
    root->Lchild = root->Rchild = NULL;

    if (start == end)  // when only one node is exists
        return root;
    
    int i;
    for (i = start; i <= end; i++)
    {
        if (pre[i] > root->data)
            break;  
    }

    root->Lchild = CreateBST_from_PreOrder(pre, start+1, i-1);
    root->Rchild = CreateBST_from_PreOrder(pre, i, end);
    
    return root;
}
int main()
{
    //  Creation Of BST From  PreOrder :
    
    int pre[] = {10,5,1,7,40,30,50};
    int startind = 0,endind = sizeof(pre)/sizeof(pre[0])-1;

    root = CreateBST_from_PreOrder(pre, startind, endind);

    cout<<"\nAfter Creation Of BST From  PreOrder function traversal is :\n";
    inOrder(root);

    return 0;
}