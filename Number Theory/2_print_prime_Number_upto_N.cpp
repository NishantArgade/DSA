#include <iostream>
// #include <string.h>
#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
	if (n == 1)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int sieve[100000]; // you can not assign size of array as a variable (formal parameter)//Only allow const size
void sieveOfErathosthenes(int n)
{
	memset(sieve, 1, sizeof(sieve));
	sieve[0] = sieve[1] = 0;

	for (int i = 2; i * i <= n; i++)
	{
		if (sieve[i] != 0)
		{
			for (int j = i * i; j <= n; j += i)
			{
				sieve[j] = 0;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (sieve[i] != 0)
			cout << i << " ";
	}
}
int main()
{ // This is not Optimal  Solution:
	// int L, R;
	// cout << "Enter Range :" << endl;
	// cin >> L >> R;
	// for (; L <= R; L++)
	// {
	// 	if (isPrime(L))
	// 		cout << L << " ";
	// }

	// The Optimal Solution you can Achieve using Sieve of Eratosthenes:
	int n;
	cin >> n;
	sieveOfErathosthenes(n);

	return 0;
}