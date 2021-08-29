#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
   
    cout<<"Befor reversing Number :"<<endl;
    while(!q.empty())
    {   
        cout<<"The element is "<<q.front()<<endl;
        s.push(q.front());
        q.pop();
    }
    cout<<"After reversing Number :"<<endl;
    while(!s.empty())
    {   
        cout<<"The element is "<<s.top()<<endl;
        s.pop();
    }

    return 0;
}