#include <iostream>
using namespace std;
struct AVLnode
{
    AVLnode *Lchild;
    int Data;
    int Height;
    AVLnode *Rchild;
} *root = NULL;

void inOrder(AVLnode *root)
{
    if (!root)
        return;
    inOrder(root->Lchild);
    cout << root->Data << " ";
    inOrder(root->Rchild);
}
int NodeHeight(AVLnode *root)
{
    if (!root)
        return 0;
    int L = NodeHeight(root->Lchild);
    int R = NodeHeight(root->Rchild);
    return (L > R) ? L + 1 : R + 1;
}
int BalanceFactor(AVLnode *root)
{
    if (!root)
        return 0;
    int LH = (root->Lchild) ? root->Lchild->Height : 0;
    int RH = (root->Rchild) ? root->Rchild->Height : 0;

    return (LH - RH);
}
struct AVLnode *LLrotation(AVLnode *root)
{
    AVLnode *p = root;
    AVLnode *pl = p->Lchild;
    AVLnode *plr = pl->Rchild;

    //Perform rotation:
    p->Lchild = plr;
    pl->Rchild = p;
    if (root == p)
        root = pl;
    return pl;
}
struct AVLnode *RRrotation(AVLnode *root)
{
    AVLnode *p = root;
    AVLnode *pr = p->Rchild;
    AVLnode *prl = pr->Lchild;

    //Perform rotation:
    p->Rchild = prl;
    pr->Lchild = p;
    if (root == p)
        root = pr;
    return pr;
}
struct AVLnode *LRrotation(AVLnode *root)
{
    AVLnode *p = root;

    //Perform rotation:
    p->Lchild = RRrotation(p->Lchild);
    return LLrotation(p);
}
struct AVLnode *RLrotation(AVLnode *root)
{
    AVLnode *p = root;

    //Perform rotation:
    p->Rchild = LLrotation(p->Rchild);
    return RRrotation(p);
}

struct AVLnode *insertion_in_AVL(AVLnode *root, int Data)
{

    if (root == NULL)
    {
        struct AVLnode *root = (struct AVLnode *)malloc(sizeof(struct AVLnode));
        root->Data = Data;
        root->Height = 1;
        root->Lchild = root->Rchild = NULL;

        return root;
    }
    else
    {
        if (Data < root->Data)
            root->Lchild = insertion_in_AVL(root->Lchild, Data);

        else if (Data > root->Data)
            root->Rchild = insertion_in_AVL(root->Rchild, Data);
    }
    root->Height = NodeHeight(root);

    if (BalanceFactor(root) == 2 && BalanceFactor(root->Lchild) == 1 ||
        BalanceFactor(root) == 2 && BalanceFactor(root->Lchild) == 0)
        return LLrotation(root);

    if (BalanceFactor(root) == -2 && BalanceFactor(root->Rchild) == -1 ||
        BalanceFactor(root) == -2 && BalanceFactor(root->Lchild) == 0)

        return RRrotation(root);

    if (BalanceFactor(root) == 2 && BalanceFactor(root->Lchild) == -1)
        return LRrotation(root);

    if (BalanceFactor(root) == -2 && BalanceFactor(root->Rchild) == 1)
        return RLrotation(root);

    return root;
}
AVLnode *removeNodes_which_Not_inRange(AVLnode *root, int K1, int K2)
{
    if (!root)
        return NULL;
    root->Lchild = removeNodes_which_Not_inRange(root->Lchild, K1, K2);
    root->Rchild = removeNodes_which_Not_inRange(root->Rchild, K1, K2);
    if (root->Data >= K1 && root->Data <= K2)
        return root;
    if (root->Data < K1)
        return root->Rchild;
    if (root->Data > K2)
        return root->Lchild;
}

int main()
{
    // insertion in AVL Tree:
    root = insertion_in_AVL(root, 6);
    root = insertion_in_AVL(root, 4);
    root = insertion_in_AVL(root, 7);
    root = insertion_in_AVL(root, 2);
    root = insertion_in_AVL(root, 5);
    root = insertion_in_AVL(root, 80);

    cout << "\nAVL Tree is with Min no pf nodes is :\n ";
    inOrder(root);

    cout << "\nAfter Remove all Nodes which is not in range of AVL Tree,new AVL tree is:\n ";
    int K1, K2;
    cout << "Enter K1 and K2 : " << endl;
    cin >> K1 >> K2;
    root = removeNodes_which_Not_inRange(root, K1, K2);
    inOrder(root);


    return 0;
}