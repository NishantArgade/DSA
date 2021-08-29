#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#define forloop for (int i = 0; i < size; i++)

int findNonDuplicateEle(int Arr[], int size)
{

	int xxor = 0;
	forloop
	{
		xxor = xxor ^ Arr[i];
	}
	return xxor;
}
void findTwoNonDuplicateEle(int Arr[], int size)
{

	int xxor = 0;
	forloop
	{
		xxor = xxor ^ Arr[i];
	}

	int rsbm = xxor & -xxor; //rsbm = right most set bit mask

	int x = 0, y = 0;
	forloop
	{
		if ((Arr[i] & rsbm) == 0)
			x = x ^ Arr[i];

		else
			y = y ^ Arr[i];
	}

	(x < y) ? cout << "x = " << x << " y = " << y << endl : cout << " y = " << y << " x = " << x << endl;
}
void findMissingAndDuplicateEle(int Arr[], int size)
{

	int xxor = 0;
	forloop
	{
		xxor = xxor ^ Arr[i];
	}
	forloop
	{
		xxor = xxor ^ i + 1;
	}

	int rsbm = xxor & -xxor; //rsbm = right most set bit mask

	int x = 0, y = 0;
	forloop
	{
		if ((Arr[i] & rsbm) == 0)
			x = x ^ Arr[i];

		else
			y = y ^ Arr[i];
	}

	forloop
	{
		if (x == Arr[i])
		{
			cout << "The Repeat element is :" << x << endl;
			cout << "The Misssing element is :" << y << endl;
			break;
		}
		else if (y == Arr[i])
		{
			cout << "The Repeat element is :" << y << endl;
			cout << "The Missing element is :" << x << endl;
			break;
		}
	}
}
int countSetBit_1(int num)
{
	int count = 0;
	while (num)
	{
		int rsbm = num & -num;
		num = num - rsbm;
		count++;
	}
	return count;
}
int countSetBit_2(int num)
{
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}
int isPowOfTwo(int num)
{
	return (num & (num - 1)) == 0 ? 1 : 0;
}
void allPossibleSubset(int Arr[], int n)
{
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (i & (1 << j))
			{
				cout << Arr[j] << " ";
			}
		}
		cout << endl;
	}
}
int findNumberOfTriplates(int Arr[], int n)
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int xxor = Arr[i];
		for (int k = i + 1; k < n; k++)
		{
			xxor = xxor ^ Arr[k];
			if (xxor == 0)
			{
				return (k - i);
			}
		}

		cout << endl;
	}
	return -1;
}
int reduceNumberTo1(int num)
{
	int res = 0;
	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else if (num == 3)
		{
			num = num - 1;
		}
		else if ((num & 3) == 1)
		{
			num = num - 1;
		}
		else if ((num & 3) == 3)
		{
			num = num + 1;
		}
		res++;
	}
	return res;
}
int ncr(int n, int r)
{
	if (n < r)
		return 0;
	int res = 1;
	for (int i = 0; i < r; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}
int solution(int num, int k, int i)
{

	int mask = 1 << i;
	int res = 0;

	if (i == 0)
		return 0;

	if ((num & mask) == 0)
	{ // if MSB is 0
		res = solution(num, k, i - 1);
	}
	else // if MSB is 1
	{
		int res1 = solution(num, k - 1, i - 1); // add 1 to the suffix
		int res0 = ncr(i, k);					// add 0 to the suffix
		res = res1 + res0;
	}
	return res;
}

int xorOfSumOfAllPair(int Arr[], int size)
{
	int xxor = 0;
	forloop
	{
		xxor ^= Arr[i];
	}
	return 2 * xxor;
}

void printAbbrivation(string s)
{
	for (int i = 0; i < (1 << s.length()); i++)
	{
		int count = 0;

		for (int j = 0; j < s.length(); j++) //000 = Pep
		{
			int b = s.length() - 1 - j; //001 = Pe1
			if ((i & (1 << b)) == 0)	//010 = P1p
			{							//011 = P2
										//100 = 1ep
				if (count == 0)			//101 = 1e1   //110 =  2p
					cout << s.at(j);

				else if (count != 0)
				{
					cout << count;
					cout << s.at(j);
					count = 0;
				}
			}
			else //if bit is on
				count++;
		}
		if (count)
			cout << count;

		cout << endl;
	}
}

int main()
{ // xxor (^) property = 1] n^n = 0   2] n^0 = n.----n=Number

	// Find one Non-dublicate number in Twise dublicate number Array by using bit manipulation.
	int A[] = {1, 1, 2, 5, 3, 2, 5};
	int n = sizeof(A) / sizeof(A[0]);
	// cout << "Non Duplicate ele is : " << findNonDuplicateEle(A, n) << endl;

	// Find Two Non-dublicate number in Twise dublicate number Array by using bit manipulation.
	int B[] = {1, 1, 2, 7, 3, 2, 8, 7};
	int n1 = sizeof(B) / sizeof(B[0]);
	// findTwoNonDuplicateEle(B, n1);

	// Find Missing and dublicate number in [1-n] Array by using bit manipulation.
	int C[] = {1, 3, 4, 2, 5, 3, 7};
	int n2 = sizeof(C) / sizeof(C[0]);
	// findMissingAndDuplicateEle(C, n2);

	//Count number of set bit in a B.bits
	// cout << countSetBit_1(7) << endl;
	// cout << countSetBit_2(7) << endl;

	// cout << isPowOfTwo(84);

	int Arr[] = {1, 2, 3}; //1,2,3
						   //   0  1  2
						   // size =3; 2^3==(1<<3)=8.
	//  0.  {} = 000 = 0
	//  1.  {1}= 001 =1
	//  2.  {2}= 010 =2
	//  3.  {1,2}= 011 =3
	//  4.  {3}= 100  =4
	//  5.  {1,3}= 101 =5
	//  6.  {2,3}= 110 =6
	//  7.  {1,2,3}= 111 =7

	// allPossibleSubset(Arr, 3);

	// Find Number of Triplate
	int D[] = {1, 3, 2, 5, 7, 2, 7, 5, 6, 4};
	int n3 = sizeof(D) / sizeof(D[0]);
	// cout << "The Number of Triplate is :" << findNumberOfTriplates(D, n3) << endl;

	// cout << "Steps required to reduce number to 1 is :" << reduceNumberTo1(3) << endl;

	// cout << "Find same number of setbit number which is less than that given num  " << solution(12, 2, 31) << endl;
	/* i.e 12= 1100 ----given Num
	       10=  1010
		    9=  1001
			6=	0110
			5=	0101
			3=	0011
	hence,there are 5 number is found which is less than number 12 used same number of setbit of 12 which is 2(11)
	*/
	/* xor of sum of all pair i.e
     A,B,C = 
    (A+A)^(A+B)^(A+C)^
    (B+A)^(B+B)^(B+C)^
    (C+A)^(C+B)^(C+C) = 2A^2B^2C = 2(A^B^C).*/

	int F[] = {1, 2, 3};
	cout << " xor of sum of all pair is " << xorOfSumOfAllPair(F, 3) << endl;
	/*  0001
	^ 0010
	^ 0011
	-------
	  0000
	2*(0) = 0 */

	string s("Pep");
	printAbbrivation(s);

	return 0;
}
