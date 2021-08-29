#include <iostream>
#include <queue>
#include <bits/stdc++.h> //include stack

using namespace std;

int ReverseFirstKElement(queue<int> &q, int k)
{
    if (q.empty() || k > q.size())
    {
        cout<<"Invalid \"k\"input or queue is Empty!"<<endl;
        return -1;
    }
    else if (k > 0)
    {
        stack<int> s;
        queue<int> q1;

        for (int i = 1; i <= k; i++)
        {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        for (int i = 0; i < q.size() - k; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
}
void print(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
int main()
{
    queue<int> q;

    q.push(10); //1
    q.push(20); //2
    q.push(30); //3
    q.push(40); //4
    q.push(50); //5
    q.push(60); //5
    q.push(70); //5

    int k = 3;
    cout << " Reversing first " << k << " Element of Queue is: " << endl;
    ReverseFirstKElement(q, k);
    print(q);

    return 0;
}