#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpanProblem(vector<int> &v)
{
    stack<pair<int, int>> s;
    vector<int> answer;

    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            answer.push_back(1);

        else if (s.top().first > v[i])
            answer.push_back(1);

        else if (s.top().first <= v[i])
        {
            while (!s.empty() && s.top().first <= v[i])
            {
                s.pop();
            }
        if (s.empty())
            answer.push_back(i + 1);
        else
            answer.push_back(i - s.top().second);
        }

        s.push({v[i], i});
    }
    return answer;
}
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> v{100, 80, 60, 70, 60, 75, 85};

    cout << "Before stockSpanProblem Function:\n";
    display(v);

    cout << "\nAfter stockSpanProblem Function:\n";
    vector<int> v1;
    v1 = stockSpanProblem(v);
    display(v1);

    return 0;
}