#include <iostream>
#include <bits/stdc++.h> //include stack
using namespace std;
// (ii) Reverse stack using Recursion(No Need to used Another stack )
//(it is recommended)space-complexity optimized

// #include <iostream>
int put_At_Last(stack<int> &s, int k)
{
    if (s.empty())
    {
        s.push(k);
        return 0;
    }
    int temp = s.top();
    s.pop();

    put_At_Last(s, k);

    s.push(temp);

    return 0;
}
int Reverse_WRecursion(stack<int> &s)
{
    if (s.empty())
    {
        return 0;
    }
    int temp = s.top();
    s.pop();

    Reverse_WRecursion(s);

    put_At_Last(s, temp);

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
    stk.push(3);
    stk.push(2);
    stk.push(1);
    stk.push(0);

    cout << "Before Recursion Reverse Operation" << endl;
    printthestack(stk);

    Reverse_WRecursion(stk);
    
    cout << "\nAfter Recursion Reverse Operation" << endl;
    printthestack(stk);

    return 0;
}
