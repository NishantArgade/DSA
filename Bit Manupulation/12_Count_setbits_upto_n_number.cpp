#include <iostream>
using namespace std;
int count_SetBits(int n)
{
	if (n == 0)
		return 0;
	int powOf2,sum=0,x;
	for (int i = 0; i <= n; i++)
	{
		if ((1 << i) <= n)
		{
			powOf2 = (1 << i);
			x = i;
		}
	}
	return sum = ((1 << (x - 1)) * x) + (n - powOf2 + 1) + count_SetBits(n - powOf2);
}
int main()
{
	cout << "The total set bits upto given number is :" << count_SetBits(11) << endl;
	return 0;
}