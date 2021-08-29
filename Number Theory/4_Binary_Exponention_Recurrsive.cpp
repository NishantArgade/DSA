#include <iostream>
using namespace std;

int power1(int x, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power1(x * x, n / 2);
	else
		return power1(x * x, n / 2) * x;
}
int power2(int x, int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n % 2 != 0)//odd
			res *= x;

		x *= x;
		n /= 2;
	}
	return res;
}
int main()

{
	cout << power1(3, 3) << endl;
	cout << power2(3, 3) << endl;
	return 0;
}