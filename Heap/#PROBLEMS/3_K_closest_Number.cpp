#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> maxheap;
    vector<int> arr{9, 15, 1, 8, 2, 5, 10};

    int N ;
    cout<<"Enter number :"<<endl;
    cin>>N;
    for (int i = 0; i < arr.size(); i++)
    {
        int deff = arr[i] - N;
        maxheap.push({deff, arr[i]});
    }
    int k;
    cout<<"how many k number you want to give "<<endl;
    cin>>k;

    while(maxheap.size()>k)
    {
        maxheap.pop();
    }
    while(!maxheap.empty()){
        cout<<maxheap.top().second<<" ";
        maxheap.pop();
    }

    

    return 0;
}