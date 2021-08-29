//  Insertion in Doubly Link List :

#include <iostream>
using namespace std;

struct BSTnode *root = NULL;

struct BSTnode
{
    int data;
    struct BSTnode *Lchild;
    struct BSTnode *Rchild;
};
struct BSTnode *BuildBSTfromDDL(int Arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    BSTnode *root = new BSTnode;
    root->data = Arr[mid];

    root->Lchild = BuildBSTfromDDL(Arr, start, mid - 1);
    root->Rchild = BuildBSTfromDDL(Arr, mid + 1, end); //== n-n/2-1

    return root;
}
void inOrder(struct BSTnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    cout << root->data << " ";
    inOrder(root->Rchild);
}

struct BSTnode *Kth_smallest_Number(struct BSTnode *root, int K, int &count)
{
    if (!root)
        return NULL;

    Kth_smallest_Number(root->Lchild, K);
    count++;

    Kth_smallest_Number(root->Rchild, K);
    if (count == K)
        return root;
}
int main()
{
    int Arr[] = {2, 3, 5, 10, 15};
    int size = 5;
    //------------------------------------------------------------------------------------
    // Build BST from sorted DDL:
    int size = countLLnodes(head);
    int start = 0, end = 4;
    root = BuildBSTfromDDL(Arr, start, end);
    cout << "\nBST is =>  ";
    inOrder(root);
    int count = 0;
    cout << Kth_smallest_Number(root, 1, count)->data;
    return 0;
}