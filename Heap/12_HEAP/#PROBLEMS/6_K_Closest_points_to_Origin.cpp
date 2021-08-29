#include <iostream>
#include <queue>
using namespace std;

int main()
{
  priority_queue<pair<int,pair<int,int>>> maxheap;
  int arr[5][2]={ {-5, 2},{ 0, 0},{1, 1},{5,6},{-2,-4} };

  for (int i = 0; i < 5; i++)
  {
    int deff = arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1];
   
    maxheap.push(pair<int,pair<int,int>>(deff,{arr[i][0],arr[i][1]} ) );
    
  }
  int k;
  cout<<"The k is :"<<endl;
  cin>>k;
  while(maxheap.size()>k){
    maxheap.pop();
  }
  cout<<"The collest points to the origin is : "<<endl;
   while(!maxheap.empty()){

     cout<<"{ "<<maxheap.top().second.first<<","<<maxheap.top().second.second<<" } "<<" ";
     maxheap.pop();

   }
  return 0;
}