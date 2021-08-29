#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

stack<int> s1;
stack<int> s2;

void enqueue(queue<int> q, int data)
{
    s1.push(data);
}
int dequeue(queue<int> q)
{
    if(s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
    }
     if (!s2.empty())
    {
        int topValue = s2.top();
        s2.pop();

        return topValue;
    }
}
int main()
{
    queue<int> q;

    enqueue(q, 10);//1
    enqueue(q, 20);//2
    enqueue(q, 30);//3 so on
    enqueue(q, 40);
    enqueue(q, 50);

    cout << "The dequeuing element is 1 " << dequeue(q) << endl;
    cout << "The dequeuing element is 2 " << dequeue(q) << endl;
    cout << "The dequeuing element is 3 " << dequeue(q) << endl;
    cout << "The dequeuing element is 4 " << dequeue(q) << endl;
    cout << "The dequeuing element is 5 " << dequeue(q) << endl;

    return 0;
}