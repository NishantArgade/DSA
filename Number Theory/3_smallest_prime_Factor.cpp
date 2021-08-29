#include <iostream>
#include <string.h>
using namespace std;

int spf[10000];

void smallestPrimeFactor(int n)
{
	memset(spf, 1, sizeof(spf));
	for (int i = 1; i <= n; i++)
		spf[i] = i;
	
	for (int i = 2; i * i <= n; i++)
	{
		if (spf[i] != 0)
		{
			for (int j = i * i; j <= n; j += i)
				if (spf[j] == j)
					spf[j] = i;
			
		}
	}
	while (n != 1)

	
	{
		cout << spf[n] << "*";
		n /= spf[n];
	}
}
int main()
{
	smallestPrimeFactor(60);
	return 0;
}