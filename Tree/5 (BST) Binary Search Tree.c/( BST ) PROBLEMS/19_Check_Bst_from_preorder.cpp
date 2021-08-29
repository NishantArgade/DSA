#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

int Check_BST_from_preOrder(vector<int> arr, stack<int> s, int root)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // start right subtree.
        while (!s.empty() && arr[i] > s.top())
        {
            root = s.top();
            s.pop();
        }

        //if any one right sub tree element is less than root then return false.
        if (root > arr[i])
            return 0;
        s.push(arr[i]);
    }
    return 1;
}

int main()
{
    vector<int> arr{10, 8, 6, 9, 15, 20,3};
    
    stack<int> s;
    int root = INT_MIN;
    // TC = O(n),      SC = O(n).
    int ans = Check_BST_from_preOrder(arr, s, root);
    ans ? printf("\n given preorder is preorder of anyone BST .\n") : printf("\n given preorder is Not preorder of any BST .\n");
    return 0;
}
