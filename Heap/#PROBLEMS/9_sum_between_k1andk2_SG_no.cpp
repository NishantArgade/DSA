#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;

    int arr[] = {5, 6, 9, 2, 1, 5, 10};
    int n = 7;

    for (int i = 0; i < n; i++){
        maxheap.push(arr[i]);
        minheap.push(arr[i]);
    }

    int k1;
    cout << "Enter k th smallest number :" << endl;
    cin >> k1;

    while (maxheap.size() > k1)
        maxheap.pop();
     
    int frist = maxheap.top();

    int k2;
    cout << "Enter k th greatest number :" << endl;
    cin >> k2;

    while (minheap.size() > k2)
        minheap.pop();
    
    int second = minheap.top();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (frist < arr[i] && arr[i] < second)
        {
            sum = sum + arr[i];
        }
    }
    cout << "The  sum between " << k1 << "smallest and " << k2 << "greatest  numbers is :" << sum << endl;

    return 0;
}