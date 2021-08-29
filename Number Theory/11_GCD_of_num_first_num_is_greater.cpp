
#include <iostream>
using namespace std;

#define li long int
#define lli long long int
#define FLoop(i, n) for (lli i = 1; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

lli power_2(lli x, lli n, lli m)
{
	lli res = 1LL;
	while (n)
	{
		if (n % 2)
			res = ((res % m) * (x % m)) % m;

		x = ((x % m) * (x % m)) % m;
		n /= 2;
	}
	return res;
}
lli GCD(lli a, lli b, lli n)
{
	if (a == b)
		return power_2(a, n, mod) + power_2(b, n, mod);

	lli num = a - b;
	lli candidate = 1;
	FLoop(i, num)
	{
		if (num % i == 0)
		{
			lli temp1 = (power_2(a, n, i) + power_2(b, n, i)) % i;
			if (temp1 == 0)
				candidate = max(candidate, i);

			lli temp2 = (power_2(a, n, num / i) + power_2(b, n, num / i)) % (num / i);
			if (temp2 == 0)
				candidate = max(candidate, num / i);
		}
	}
	return candidate % mod;
}
int main()
{
	cout << GCD(10, 1, 1);
	return 0;
}