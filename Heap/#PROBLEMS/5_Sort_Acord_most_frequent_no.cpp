#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> maxheap;

    vector<int> arr{1, 3, 4, 5, 6, 2, 2, 1, 1, 1, 3, 3};
    vector<int> frq;
    unordered_map<int, int> mp; // size complexity = O(n+k) k for map size

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    unordered_map<int, int>::iterator itr;

    for (itr = mp.begin(); itr != mp.end(); ++itr)
    {
        maxheap.push({itr->second, itr->first});
    }
    cout << "Sorted According most ferquency of numbers :" << endl;
    while (!maxheap.empty())
    {
        for (int i = 0; i < maxheap.top().first; i++)
        {
            cout << maxheap.top().second << " ";
        }
        maxheap.pop();
    }
    return 0;
}