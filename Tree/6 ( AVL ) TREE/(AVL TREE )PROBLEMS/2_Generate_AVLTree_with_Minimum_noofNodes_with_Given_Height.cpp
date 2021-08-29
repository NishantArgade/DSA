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
int count = 1;
AVLnode *Generate_HB0_AVLTree(int h)
{
    struct AVLnode *temp;
    if (h <= 0)
        return NULL;
    temp = new AVLnode;
    temp->Lchild = Generate_HB0_AVLTree(h - 1);
    temp->Data = count++;
    temp->Rchild = Generate_HB0_AVLTree(h - 1);
    return temp;
}
AVLnode *Generate_AVLTree(int h)
{
    struct AVLnode *temp;
    if (h <= 0)
        return NULL;
    temp = new AVLnode;
    temp->Lchild = Generate_AVLTree(h - 1);
    temp->Data = count++;
    temp->Height = 1;
    temp->Rchild = Generate_AVLTree(h - 2);
    return temp;
}
int main()
{
    // insertion in AVL Tree:
    // root = insertion_in_AVL(root, 6);
    // root = insertion_in_AVL(root, 5);
    // root = insertion_in_AVL(root, 9);
    // root = insertion_in_AVL(root, 3);
    // root = insertion_in_AVL(root, 8);
    // root = insertion_in_AVL(root, 7);
    // root = insertion_in_AVL(root, 10);
    // root = insertion_in_AVL(root, 2);
    // root = insertion_in_AVL(root, 2);

    int Height = 3;
    // Generate Hight Balance HB(0) AVL Tree :           (2)
    // root = Generate_HB0_AVLTree(Height); //             /  \
                                        //            (1)  (3)
                                 
    // cout << "\nHB0 AVL Tree is : ";
    // inOrder(root);

    // Generate AVL Tree With Minimum Number of Nodes:         (3)
    root = Generate_AVLTree(Height); //                        /  \
                                      //                     (2)  (4)
                                     //                      /
                                     //                    (1)
    cout << "\nAVL Tree is with Min no pf nodes is : ";
    inOrder(root);

    return 0;
}