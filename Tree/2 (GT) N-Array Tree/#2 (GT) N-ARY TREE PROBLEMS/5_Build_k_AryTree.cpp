
//3. Way to represent N- Ary Tree(Generic Tree )(Recomended ):

#include <iostream>
#include <vector>

using namespace std;

struct NTNode *root, *Cnode, *Snode;

// ( Generic Tree )N-Ary Tree Node:
struct NTNode
{
    int data;
    vector<struct NTNode *> Child;
};

struct NTNode * Build_K_AryTree(int Arr[], int n, int k, int ind)
{
    struct NTNode *NewNode = new NTNode;
    NewNode->data = Arr[ind];
    // NewNode->Child.push_back(NULL);

    for (int i = 0; i < k; i++)
    {
        if (k * ind + i < n)
        {
            ind++;
            root = Build_K_AryTree(Arr, n, k, ind);
            NewNode->Child.push_back(root);
        }
        else
        {
           NewNode->Child.push_back(NULL); 
        }    
        
    }
    return NewNode;
}
int main()
{

    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10, k = 3, ind = 0;
    struct NTNode *newroot = Build_K_AryTree(Arr, n, k, ind);
    cout << newroot->data << " ";
    cout << newroot->Child[0]->data << " ";
    cout << newroot->Child[1]->data << " ";
    cout << newroot->Child[2]->data << " ";
    cout << newroot->Child[0]->Child[0]->data << " ";
    cout << newroot->Child[0]->Child[1]->data << " ";
    // cout << newroot->Child[0]->Child[2]->data << " ";
    // cout << newroot->Child[1]->Child[0]->data << " ";
    // cout << newroot->Child[1]->Child[1]->data << " ";
    // cout << newroot->Child[1]->Child[2]->data << " ";
   

    return 0;
}