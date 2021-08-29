#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


vector<int> NSL(vector<int> &Arr)
{
    vector<int> vec;
    stack<pair<int,int>> st;

    for (int i = 0; i <= Arr.size() - 1; i++)//dir -->
    {
        if (st.empty())
            vec.push_back(-1);

        else if (st.top().first < Arr[i])
            vec.push_back(st.top().second);

        else if (st.top().first >= Arr[i])
        {
            while (!st.empty() && st.top().first >= Arr[i])
                st.pop();

            if (st.empty())//i.e Not present smallest element in the stack
                vec.push_back(-1);

            else   //i.e push_back into the vec if st.top() < Arr[i]
                vec.push_back(st.top().second);
        }

        st.push({Arr[i],i});// store the value into the stack from forward direction(--->)
    }

    return vec;
}

vector<int> NSR(vector<int> &Arr,int minInd)
{
    vector<int> vec;
    stack<pair<int,int>> st;

    for (int i = Arr.size() - 1; i >= 0; i--)// Dir <---
    {
        if (st.empty())
            vec.push_back(minInd);

        else if (st.top().first < Arr[i])
            vec.push_back(st.top().second);

        else if (st.top().first >= Arr[i])
        {
            while (!st.empty() && st.top().first >= Arr[i])
                st.pop();

            if (st.empty())
                vec.push_back(minInd);

            else   //i.e push_back into the vec if st.top() < Arr[i]
                vec.push_back(st.top().second);
        }

        st.push({Arr[i],i});// store the value into the stack from backward direction(<---)
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
    vector<int> A{2,1,5,6,2,3};
    vector<int> leftInd;
    vector<int> rightInd;

    leftInd = NSL(A);
    // display(leftInd);

    int n=A.size();
    rightInd = NSR(A,n+1);
    // display(rightInd);

    int maxArea = 0;
    int width,hight,Area;
    for (int i = 0; i < A.size(); i++)
    {
        width = rightInd[i] - leftInd[i]-1;
        Area = A[i]*width;
        if (maxArea < Area)
        {
            maxArea = Area;
        }   
    }

    printf("The Max Area of given Histogram is : %d",maxArea);
    

    
    return 0;
}