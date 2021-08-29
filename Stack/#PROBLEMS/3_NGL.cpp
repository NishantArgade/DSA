// NSR-Nearest Greatest to the Left using stack 
// Time-complexity = O(n) // insted of O(n^2)
// space-complecity =O(n)

#include <iostream>
#include <vector>// include vector STL
#include <bits/stdc++.h>// include stack STL
using namespace std;

vector<int> NGL(vector<int> &Arr)
{
    vector<int> vec;
    stack<int> st;

    for (int i = 0; i <= Arr.size() - 1; i++)//dir -->
    {
        if (st.empty())
            vec.push_back(-1);

        else if (st.top() > Arr[i])
            vec.push_back(st.top());

        else if (st.top() <= Arr[i])
        {
            while (!st.empty() && st.top() <= Arr[i])
                st.pop();

            if (st.empty())//i.e Not present greater element in the stack
                vec.push_back(-1);

            else   //i.e push_back into the vec if st.top() > Arr[i]
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
    vector<int> A{5, 2,1,3,4,2};

    cout << "Befor Nearest Greatest to the Left Function :" << endl;
    display(A);

    cout << "After Nearest Greatest to the Left Function :" << endl;
    vector<int> vec1;
    vec1 = NGL(A);

    display(vec1);

    return 0;
}