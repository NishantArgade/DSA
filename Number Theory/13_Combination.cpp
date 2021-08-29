#define li long int
#define lli long long int
#define RFL(i, n) for (int i = 0; i < n; i++)
#define RFL_k(k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define m 1000000007

#include <iostream>
using namespace std;
int A[1000000];

int power(int x, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2)
			res = ((res) % m * 1LL * (x) % m) % m;
		x = ((x) % m * 1LL * (x) % m) % m;
		n /= 2;
	}
	return res;
}
int C(int n, int r)
{
	if (r > n)
		return 0;

	int res = A[n] % m;
	res = ((res % m) * 1LL * power(A[r], m - 2) % m) % m;
	res = ((res % m) * 1LL * power(A[n - r], m - 2) % m) % m;

	return res;
}
int main()
{
	A[0] = A[1] = 1;
	RFL_k(2, 1000001)
		A[i] = A[i - 1] * 1LL * i;

	int q, n, r;
	cin >> q;
	while (q--)
	{
		cin >> n >> r;
		cout << C(n, r) << endl;
	}
	return 0;
}