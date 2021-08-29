// NGR-Nearest Greater to Right using stack 
// Time-complexity = O(n) // insted of O(n^2)
// space-complecity =O(n)

#include <iostream>
#include <vector>// include vector STL
#include <bits/stdc++.h>// include stack STL
using namespace std;

vector<int> NGR(vector<int> &Arr)
{
    vector<int> vec;
    stack<int> st;

    for (int i = Arr.size() - 1; i >= 0; i--)// Dir <---
    {
        if (st.empty())
            vec.push_back(-1);

        else if (st.top() > Arr[i])
            vec.push_back(st.top());

        else if (st.top() <= Arr[i])
        {
            while (!st.empty() && st.top() <= Arr[i])
                st.pop();

            if (st.empty())
                vec.push_back(-1);

            else   //i.e st.top() > Arr[i]
                vec.push_back(st.top());
        }

        st.push(Arr[i]);// store the value into the stack from backward direction(<---)
    }
    reverse(vec.begin(), vec.end());//
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
    vector<int> A{3, 5,8,10,-1,0};

    cout << "Befor Nearest Greater to the Right Function :" << endl;
    display(A);

    cout << "After Nearest Greater to the Right Function :" << endl;
    vector<int> vec1;
    vec1 = NGR(A);

    display(vec1);

    return 0;
}