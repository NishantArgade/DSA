#define li long int
#define lli long long int
#define rfl(i, k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int t, m, n, c;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		int g = __gcd(m, n);

		if (g > 1)
			cout 
				 << -1<< endl;
		else
			cout <<(m*n-m-n+1)<< endl;
	}
	return 0;
}