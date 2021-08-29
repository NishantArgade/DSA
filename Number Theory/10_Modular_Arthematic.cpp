#include <bits/stdc++.h>
using namespace std;

int main()
{ /*
	//Do you know ?
	// * data types and their capacity for store number :
	// 1. -10^9 < int < 10^9
	// 2. -10^12 < long int < 10^12
	// 3. -10^18 < long long int < 10^18

# code 1 :
 ex int n = 100;
	int counter = 1;
	int arr[10];
	for (int i = 0; i < n; i++)
	{
		counter++;
		arr[i]=i;
	
	}

	*Time complixity is O(n)

# code 2 :
	int n = 10 ^ 8;
	int counter = 1;
	while (n)
	{
		n = / 2;
		counter++;	
	}
	*Time complixity is O(log(n))
  Explanation :
	n =  2^a <---------a means No.of steps required to divide this n completly(0).
	Taking log on both sides
	log(n) = log(2^a) = alog(2) = a  
	hence a = log(n)
	log(n) times divid number n 
	so that, loop run log(n) since time comlexity is O(log(n)).

 Q. Why O(log(n)) is better than O(n) ?
 --> it reduce or Optimise Time complixity.
  ex.in code 1: loop run (iteration) is 10^8 = 100000000 iterations which is costly.
     in code 2: loop run (iteration) is log(10^8) = 8*log(10) = 8*3 = 24 iterations.
	
*************** Types of Error in compataive codding sites : *****************************

	// 1. Run time error OR (segmentation fault error)= (Memory manegment related issue )ex. Unwell behavior of your code or access invalid memory

	ex 1]   int n = 100;
			int arr[10];
			for (int i = 0; i < n; i++)
				arr[i] = i;

	ex 2]   void fun()
			{
				fun();
				fun();
				fun();
			}
	2. TLE(Time Limit exceed):

    ex 1]  void fun()
			{
				fun();
			}

	# Time				# Iterations 
		1s				  10^7          
		10s				  10^8
		100s              10^9
		1000s(15 min)     10^10
		10000s            10^11 
        so on...  
*/
//--------------------Modular Property:-------------------------------------------------------------------
	/*

	* gcd(a,0) = a

    # Relation of congurances :
       if
	     a con b (%m)
		then
      1. ( a =remainder) == (b =remainder)   
         i.e ( a%m ) == ( b%m )   

	  2. a-b con(=) 0
		 ex.
		 12 = 2 (%10)
		 12-2 = 10
		 10%10 == 0

      3. a^k con b^k
	    ex.
         13 = 1 ( % 3)
         13^8 = 1^8 
		 13^8 == 1^8

		//1. (a+b)%m = ((a%m)+(b%m))%m
		//2. (a-b)%m = ((a%m)-(b%m))%m
		//3. (a*b)%m = ((a%m)*(b%m))%m
		//4. (a/b)%m = ((a%m)*(b^-1%m))%m

*/
		return 0;
	}