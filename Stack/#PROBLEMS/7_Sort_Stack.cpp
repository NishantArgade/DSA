//================================ Stack Element Sort =================================================================================
#include <iostream>
#include <bits/stdc++.h> //include stack
using namespace std;

int Sort_Stack(stack<int> &s, int k)
{
    if (s.empty() || k < s.top())// if you want Decreasing order of Sort then change the sign here(>);
    {
        s.push(k);
        return 0;
    }
    int temp = s.top();
    s.pop();

    Sort_Stack(s, k);

    s.push(temp);

    return 0;
}
int Sort_Function(stack<int> &s)
{
    if (s.empty())
    {
        return 0;
    }
    int temp = s.top();
    s.pop();

    Sort_Function(s);

    Sort_Stack(s, temp);

    return 0;
}
int printthestack(stack<int> &s1)
{
    if (s1.empty())
        return 1;

    cout << s1.top() << " ";
    int temp = s1.top();
    s1.pop();

    printthestack(s1);
    s1.push(temp);
    return 0;
}
int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(4);
    stk.push(35);
    stk.push(-2);
    stk.push(15);
    stk.push(45);
    stk.push(84);
    stk.push(45);

    cout << "Before Sort Operation" << endl;
    printthestack(stk);

    Sort_Function(stk);
    
    cout << "\nAfter Sort Operation" << endl;
    printthestack(stk);

    return 0;
}
