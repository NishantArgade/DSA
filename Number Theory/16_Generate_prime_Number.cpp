#define li long int
#define lli long long int
#define rfl(i, k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>
vi primes;
void sieve(int max)
{
	vi vec(max + 1, 0);
	vec[1] = 1;

	for (int i = 2; i <= max; i++)
	{
		if (vec[i] == 0)
		{
			for (int j = 2 * i; j <= max; j += i)
			{
				vec[j] = 1;
			}
		}
	}
	rfl(i, 2, max) if (vec[i] == 0)
		primes.emplace_back(i);
}
void init(int L, int R)
{
	if (L == 1)
		L++;

	vi ar(R - L + 1, 0);
	for (int p : primes)
	{
		if (p * p <= R)
		{
			int i = (L / p) * p;
			if (i < L)
				i += p;
				for (; i <= R; i+=p)
				{
					if(i != p)
					ar[i-L]=1;
				}
				
		}
	}
	for (int i = 0; i <R-L+1  ; i++)
	{
		if(ar[i]==0)
		cout<<L+i<<" ";

	}
	
}
int main()
{
	sieve(100001);
	int t, L, R;
	while (t--)
	{
		cin >> L >> R;
		init(L, R);
		cout << endl;
	}
	return 0;
}