// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum_of_bits_diff(vector<int> Arr)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		int count = 0, Oncnt = 0, Offcnt = 0;
		for (int x : Arr)
		{
			if ((x & (1 << i)) != 0)
				Oncnt++;
			else
			{
			}
		}
		Offcnt = Arr.size() - Oncnt;
		sum += Oncnt * Offcnt * 2;
	}
	return sum;
}
int main()
{
	vector<int> Arr = {23, 25, 21, 18};
	// sum_of_bits_diff(Arr);
	cout << "The sum of bit diff is : " << sum_of_bits_diff(Arr) << endl;
	return 0;
}