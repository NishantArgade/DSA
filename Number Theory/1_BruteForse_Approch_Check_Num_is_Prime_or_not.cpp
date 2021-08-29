#include <iostream>
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
int main()
{
    isPrime(6)?cout<<"prime":cout<<"Not Prime";
	
	return 0;
}