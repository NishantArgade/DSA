#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minheap;

    int arr[] = {7, 6, 8, 1, 9, 5, 3};
    int k;
    cout << "find Kth nearest sorted number :" << endl;
    cin >> k;
    for (int i = 0; i <= k; i++)
    {
        minheap.push(arr[i]);
    }
    cout << minheap.top()<<" ";
    minheap.pop();

    for (int i = k + 1; i < minheap.size(); i++)
    {
        minheap.push(arr[i]);
        cout << minheap.top()<<" ";;
        minheap.pop();
    }

    while (minheap.size() > 0)
    {
        cout << minheap.top()<<" ";
        minheap.pop();
    }

    return 0;
}