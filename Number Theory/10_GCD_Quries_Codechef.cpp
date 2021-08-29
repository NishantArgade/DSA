#define pb push_back
#define ff first
#define ss second
#define li long int
#define lli long long int
#define RFL(i, n) for (int i = 0; i < n; i++)
#define RFL_k(k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007
#define PI 3.141592653589793238460
#define pirii pair<int, int>
#define veci vector<int>
#define vecpirii vector<pirii>
#define el endl

#include <iostream>
using namespace std;

lli ar[100000], pre[100000], suf[100000];

lli GCD(lli a, lli b)
{
	if (b == 0)
		return a;
	else
		GCD(b, a % b);
}
int main()
{
	lli t, q, n, L, R;
	cin >> t;
	cin >> q;

	cin >> n;
	RFL_k(1, n)
			cin >>ar[i];

		pre[0] = suf[n + 1] = 0;
		
	while (t--)
	{
		cin >> L >> R;

		RFL_k(1, n)
			pre[i] = GCD(pre[i - 1], ar[i]);

		for (lli i = n; i >= 1; i--)
		{
			suf[i] = GCD(suf[i + 1], ar[i]);
		}

		int ans = GCD(pre[L-1], suf[R+1]);
		cout<<ans<<el;
	}
	return 0;
}