#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void minXorPair(vector<int> A)
{
	vector<pair<int, int>> vec;
	int min = INT_MAX;
	for (int i = 0; i < A.size() - 1; i++)
	{
		int MinXor = A[i] ^ A[i + 1];

		if (MinXor < min)
		{
			min = MinXor;
			vec.emplace_back(A[i], A[i + 1]);
		}
		else if (MinXor == min)
		{
			vec.emplace_back(A[i], A[i + 1]);
		}
	}
	cout<<"The Minimum xor pair is : "<<endl;
	for (auto x : vec)
	{ 
		cout << x.first << "^" << x.second << endl;
	}
}
int main()
{
	vector<int> A{12, 12, 32, 34, 45, 45, 32};
	minXorPair(A);
	return 0;
}