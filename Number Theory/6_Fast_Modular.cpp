#include <iostream>
using namespace std;

int power(int x, int n, int mod)
{
	
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	int res = 1;
	while (n > 0)
	{
		if (n % 2 != 0) //odd
			res = (res * x) % mod;

		n /= 2;
		x = (x * x) % mod;
	}
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cout << power(2, 5, 13);
	return 0;
}