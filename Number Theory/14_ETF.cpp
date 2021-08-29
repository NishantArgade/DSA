#define li long int
#define lli long long int
#define RFL(i, n) for (int i = 0; i < n; i++)
#define RFL_k(k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

#include <iostream>
using namespace std;
int ETF(int n)
{
	int res = n;
	for (int p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
				n /= p;

			// p^k =(P^k*(p-1))/p
			res = res * (p - 1);
			res = res / p;
			
		}
	}
	if (n > 1)
	{
		res *= (n - 1);
		res /= n;
	}
	return res;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << "ETF(" << n << ") : " << ETF(n) << endl;
	}

	return 0;
}