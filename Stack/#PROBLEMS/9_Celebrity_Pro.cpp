#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int CelebrityProblem(vector<vector<int>> & v1){
    stack<int> s1;
    for (int i = 0; i<v1.size(); i++)
        s1.push(i);
    
    while (s1.size()>1)
    {
        int temp1 = s1.top();
        s1.pop();

        int temp2 = s1.top();
        s1.pop();

        if (v1[temp1][temp2])
           s1.push(temp2);
        else
           s1.push(temp1);
        
    }

    int Celebrity =  s1.top();

    // for (int i = 0; i < v1.size(); i++)
    // {
    //     if ( i== s1.top())
    //         continue;
        
    //     if (v1[Celebrity][i]==1)
    //         return -1;
        
    //     if (v1[i][Celebrity]!=1)
    //         return -1;
        
    // }
    return Celebrity; 
}

int main(){
    vector<vector<int>> v1{ {0,0,1,1},
                            {1,0,1,0},
                            {0,0,0,0},
                            {0,1,1,0} };
    
   int celebrity =  CelebrityProblem(v1);

   if (celebrity == -1)
      cout<<"No celebrity Exists !";

   else
    cout<<"Celebrity Person Number is : "<< celebrity; 
   
   
    return 0;
}