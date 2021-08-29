#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    char val;
    int freq;
    struct node *Lchild, *Rchild;
};
struct compare
{
    bool operator()(struct node *l, struct node *r)
    { // min frequency give highest priority
        return (l->freq > r->freq);
    }
};
struct node *getnode(char val, int freq, struct node *l, struct node *r)
{
    struct node *newnode = new node;
    newnode->val = val;
    newnode->freq = freq;
    newnode->Lchild = l;
    newnode->Rchild = r;

    return newnode;
}

struct node *Haffman_coding(char str[], int freq[], int n)
{
    priority_queue<struct node *, vector<struct node *>, compare> minheap;

    for (int i = 0; i < n; i++)
        minheap.push(getnode(str[i], freq[i], nullptr, nullptr));

    while (minheap.size() != 1)
    {
        struct node *left = minheap.top();
        minheap.pop();
        struct node *right = minheap.top();
        minheap.pop();

        minheap.push(getnode('\0', left->freq + right->freq, left, right));
    }
    return minheap.top();
}

void encode(struct node *root, string &storeIncodedStr, string str)
{
    if (!root->Lchild && !root->Rchild)
    {
        cout << root->val << " : " << str << endl;
        storeIncodedStr += str;
        return;
    }

    encode(root->Lchild, storeIncodedStr, str + "0");
    encode(root->Rchild, storeIncodedStr, str + "1");
}
void decode(struct node *root, string storeIncodedStr, int &index)
{
    if (!root->Lchild && !root->Rchild)
    {
        cout << root->val;
        return;
    }
    index++;
    if (storeIncodedStr[index] == '0')
        decode(root->Lchild, storeIncodedStr, index);

    decode(root->Rchild, storeIncodedStr, index);
}
int main()
{ /* Haffman Coding :(Lossless data compress method)
   
    use: it is use for compress text ,data,pdf etc...

    logic:  
    1.add two low frequency word until make complate a tree.
    2.in that tree asign left child 0 and right child 1;
    3.follow this 0/1 path and you will get compress code for each char.
    4.leaf node is always a charactor and nonleaf node are not char.
    5.High frequency char is near to the root node  
    6.low frequency char is far away from the root node  
    that's way for High freq char Haffman code is shorter
    and low freq char haffman code is larger.
    
    */
    char str[] = {'A', 'B', 'C', 'D'};
    int freq[] = {10, 6, 80, 34};
    int n = sizeof(str) / sizeof(str[0]);

    struct node *root = Haffman_coding(str, freq, n);

    cout << "\nencoding using haffman coding method : " << endl;
    string storeIncodedStr = "";
    encode(root, storeIncodedStr, "");

    cout << "\ndecoding of haffman code : " << endl;
    int i = -1;
    decode(root, storeIncodedStr, i);

    return 0;
}