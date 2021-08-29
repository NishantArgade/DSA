// NSR-Nearest Smallest to the Left using stack 
// Time-complexity = O(n) // insted of O(n^2)
// space-complecity =O(n)

#include <iostream>
#include <vector>// include vector STL
#include <bits/stdc++.h>// include stack STL
using namespace std;

vector<int> NSL(vector<int> &Arr)
{
    vector<int> vec;
    stack<int> st;

    for (int i = 0; i <= Arr.size() - 1; i++)//dir -->
    {
        if (st.empty())
            vec.push_back(-1);

        else if (st.top() < Arr[i])
            vec.push_back(st.top());

        else if (st.top() >= Arr[i])
        {
            while (!st.empty() && st.top() >= Arr[i])
                st.pop();

            if (st.empty())//i.e Not present smallest element in the stack
                vec.push_back(-1);

            else   //i.e push_back into the vec if st.top() < Arr[i]
                vec.push_back(st.top());
        }

        st.push(Arr[i]);// store the value into the stack from forward direction(--->)
    }

    return vec;
}

void display(vector<int> &v)
{
    cout << "the element in vector is :" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> A{3, 5,2,8,4,9};

    cout << "Befor Nearest Smallest to the Left Function :" << endl;
    display(A);

    cout << "After Nearest Smallest to the Left Function :" << endl;
    vector<int> vec1;
    vec1 = NSL(A);

    display(vec1);

    return 0;
}