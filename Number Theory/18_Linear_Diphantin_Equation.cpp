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

	int t, a, b, c;
	cin >> t;
	while (t--)
	{                                                                         
		cin >> a >> b;
		int g = __gcd(a, b);

		if (c % g == 0)
			cout << t
				 << " : Yes,This is valid Linear diphantin equation " << endl;
		else
			cout <<t<< " : No,This is not valid Linear diphantin equation " << endl;
	}
	return 0;
}