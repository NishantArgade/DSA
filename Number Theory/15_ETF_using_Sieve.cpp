#define li long int
#define lli long long int
#define RFL(i, n) for (int i = 0; i < n; i++)
#define RFL_k(k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

#include <iostream>
using namespace std;
int A[1000000];

void ETF(int n)
{
	RFL_k(2, n)
	{
		if (A[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				A[j] *= (i - 1);
				A[j] /= i;
			}
		}
	}
}
int main()
{
	int n, t;
	cin >> n >> t;
	RFL_k(1, n)
		A[i] = i;
	ETF(n);
	
	while (t--)
	{
		int i;
		cin >> i;
		cout << A[i]<<endl;
	}
	return 0;
}
