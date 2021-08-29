#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxheap;

    maxheap.push(1);
    maxheap.push(42);
    maxheap.push(30);
    maxheap.push(45);
    maxheap.push(10);

    int k1;
    cout << "find k smallest number enter k : " << endl;
    cin >> k1;

    while (maxheap.size() > k1)
    {
        maxheap.pop();
    }
    cout << "The " << k1 << " smallest number is " << maxheap.top()<<endl;

    priority_queue<int,vector<int>,greater<int>> minheap;

    minheap.push(1);
    minheap.push(42);
    minheap.push(30);
    minheap.push(45);
    minheap.push(10);

    int k2;
    cout << "find k greatest number enter k : " << endl;
    cin >> k2;

    while (minheap.size() > k2)
    {
        minheap.pop();
    }
    cout << "The " << k2 << " greater number is " << minheap.top();

    return 0;
}