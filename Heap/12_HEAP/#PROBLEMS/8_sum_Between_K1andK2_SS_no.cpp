#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxheap;

    int arr[] = {5, 6, 9, 2, 1, 5, 10};
    int n = 7;
    for (int i = 0; i < n; i++)
        maxheap.push(arr[i]);

    int val[n];
    int i = 0;
    int k1;
    cout << "Enter k1 th smallest number  :" << endl;
    cin >> k1;
    while (maxheap.size() > k1)
    {
        val[i] = maxheap.top();
        maxheap.pop();
        i++;
    }
    int frist = maxheap.top();

    for (int j = 0; j < n - k1; j++)
    {
        maxheap.push(val[j]);
    }
    int k2;
    cout << "Enter k2 th smallest number :" << endl;
    cin >> k2;
    while (maxheap.size() > k2)
    {
        maxheap.pop();
    }
    int second = maxheap.top();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (frist < arr[i] && arr[i] < second)
        {
            sum = sum + arr[i];
        }
    }
    cout << "The  sum between " << k1 << "smallest and " << k2 << "smallest numbers is :" << sum << endl;

    return 0;
}