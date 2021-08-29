#define li long int
#define lli long long int
#define RFL(i, n) for (int i = 0; i < n; i++)
#define RFL_k(k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
// #define mod 1000000007

#include <iostream>
using namespace std;

lli pow(lli x, lli n,lli mod)
{
	lli res = 1;
	while (n)
	{
		if (n % 2)
			res = ((res % mod) * (x % mod)) % mod;

		x = ((x % mod) * (x % mod)) % mod;
		n /= 2;
	}
	return res;
}
int main()
{
	lli a = 4ll;
	lli n = 7ll; //must be prime
	cout << "a^-1 :" << pow(a, n - 2,n);
	return 0;
}