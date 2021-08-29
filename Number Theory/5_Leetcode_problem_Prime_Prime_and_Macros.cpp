#include <iostream>
#include <string.h>
using namespace std;

int prime[10000];

int smallestPrimeFactor(int n)
{
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] != 0)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	int pp[1000] = {0};
	for (int j = 2; j <= n; j++)
	{
		int count = 0;

		for (int i = 2; i <= j; i++)
		{
			if (prime[i])
			{
				count++;
			}
			if (prime[count] && prime[i])
				pp[j] = 1;
			else
				pp[j] = 0;
		}
	}
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		res += pp[i];
	}
	return res;
}
int main()
{
	cout << smallestPrimeFactor(11);
	return 0;
}