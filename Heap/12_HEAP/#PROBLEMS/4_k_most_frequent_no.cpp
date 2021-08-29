#include<iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;

int main()
{
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > minheap;

    vector<int> arr{1,2,3,4,5,6,2,2,1,1,1,3,3,5};
    vector<int> frq;
    unordered_map<int,int> mp; // size complexity = O(n+k) k for map size

    for (int i = 0; i < arr.size() ; i++)
    {
        mp[arr[i]]++;
    }

    unordered_map<int,int>::iterator itr;

     for (itr = mp.begin(); itr != mp.end(); ++itr){
        minheap.push({itr->second,itr->first});
    }
    int k;
    cout<<"Enter k numbers"<<endl;
    cin>>k;
    while(minheap.size()>k){
       minheap.pop();
    }
    while(!minheap.empty()){
        cout<<"The most frequent number is : "<<minheap.top().second<<endl;
        minheap.pop();
    }
    return 0;
}