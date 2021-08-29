#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(1);
    minheap.push(1);
    minheap.push(1);
    minheap.push(1);
    minheap.push(1);

    int sum,cost = 0;
    while (minheap.size() >= 2)
    {

        int frist = minheap.top();
        minheap.pop();

        int second = minheap.top();
        minheap.pop();

        sum = frist + second;
        cost = cost + sum;
        minheap.push(sum);
    }
    cout<<"The minimum cost for roop is : "<<cost;
    return 0;
}