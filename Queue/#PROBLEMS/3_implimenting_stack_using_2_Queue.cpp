#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;

void push(int data)
{
    q1.push(data);
}
int pop()
{
    if (!q1.empty())
    {
        int i = 1;
        while (i < q1.size())
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val =q1.front();
        q1.pop();
        return val;
    }
    else if (!q2.empty())
    {
        int i = 1;
        while (i < q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        int val =q2.front();
        q2.pop();
        return val;
    }

}
    int main()
    {
        stack<int> s;

        push(10); //1
        push(20); //2
        push(30); //3 so on
        push(40);
        push(50);

        cout << "The dequeuing element is 1 " << pop() << endl;
        cout << "The dequeuing element is 2 " << pop() << endl;
        cout << "The dequeuing element is 3 " << pop() << endl;
        cout << "The dequeuing element is 4 " << pop() << endl;
        cout << "The dequeuing element is 5 " << pop() << endl;

        return 0;
    }