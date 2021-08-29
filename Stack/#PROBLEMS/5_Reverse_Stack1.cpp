
// (i) Reverse stack using Extra space(using Another stack )
//(Not recommended)space-complexity increases

#include <iostream>
#include <bits/stdc++.h> // include stack
using namespace std;

int Reverse_ExtraSpace(stack<int> &stk)
{
    stack<int> stk2;
    
    while (!stk.empty())
    {
        stk2.push(stk.top());
        stk.pop();
    }
    stack<int> &temp = stk;
    stk = stk2;
    stk2 = temp;
    return 1;
}
int printthestack(stack<int> &s1)
{
    if (s1.empty())
        return -1;

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

    cout << "Before Reverse function"<<endl;
    printthestack(stk);
    cout << endl;

    cout << "after Reverse function"<<endl;
    Reverse_ExtraSpace(stk);
    printthestack(stk);

    return 0;
}