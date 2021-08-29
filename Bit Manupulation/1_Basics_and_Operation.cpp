/*  ********   BIT MANIPULATION   ********* 

                         001011001<---Least Significant bit
    most significant bit --^
	
    How to find right-most setbit mask(rsbm)?
    rsbm = x & (-x);------(-x = 2's compliment = ~x+1)

    1.computer store data in binary bits formate
      and at the time of retriving convert B.bits to decimal formate.

	# D 2 B => 
    +ve num - 1.Direct convert in B.bits
	          2.Fit into bits
    -ve num - 1.egnore -ve sign
	          2.convert num into binary
			  3.2's compliment 
	          4.Fit into bits
	# B 2 D => 
    MSB == 0 - 1.Direct convert into Decimaml
	          2.give +ve sign
    MSB == 1 - 1. 2's compliment 
	          2.convert it to Decimal
			  3.give -ve sign

	2.for decimal number represent in binary formate:
		byte =  8 bits i.e (2^7...,+2^2+2^1+2^0); Rang= -2^7 to (2^7)-1
		short = 16 bits i.e (2^15...,+2^2+2^1+2^0);Rang= -2^15 to (2^15)-1
		int =   32 bits i.e (2^31...,+2^2+2^1+2^0).Rang= -2^31 to (2^31)-1
		long =  64 bits i.e (2^63...,+2^2+2^1+2^0).Rang= -2^63 to (2^63)-1

	3.Way of store data in computer:
		index 210
		ex. (274)dec = 2x10^2+7x10^1+4x10^0
					= 200+70+4 = 274
		ex. (101)bin = 1x2^2+0x2^1+1x2^0
					= 4+0+1 = 5

	4.+ve num represent normal B.bit representation
	5.-ve num also represent in convert normal B.bit into it's 2's compliment = 1's compliment(invert(~)+1)
    * 2's compliment  == -num
	6.Bit wise Operator:
	 [  &,|,~,^,<<,>>,>>> ]
	    - And (&) ->  1 if both are 1.( 0 is Most powerfull than 1)
		- or (|) ->  0 if both are 0.( 1 is most powerfull than 0) for 
		- xor (^) ->  0 if both are same. num^num = 0 and 0^num = num
		- not or once Compliment(~) ->  1'st compliment(invert B,bit)
		- left Shift (<<) -> shift num to the left by position.(indecate num multiply by two) 
		- Right Shift (>>) -> shift num to the right by position (indecate num divide by two)  


    7.Even number = whose least significant(last bit) is 0. ex 0110 = 6
    8.Odd number = whose least significant(last bit) is 1.  ex 1011 = 11
   
    9.Masking: Add another number with & or | operation to the given number is called masking.
		1001    1001             
	  & 0001  | 0001  <--Mask 
	  ------  --------
	    0001    1001   

	10.	if n = 10 =(1010) (toggle upto LSB)
	 then  n-1 = 9 =(1001) 
	 if (n & n-1)==0 where n is in 2's power(n = 2^1, n = 2^2.....)         

    11. 2^n == (1<<n).
	   ex. 2^3  == 8
	      1<<3 == 8
		  0001
	      1000 = 8
	*/
#include <iostream>
using namespace std;
 /* 1) on  (|) --> 1011 0 101 = x
            | 0000 1 000 = mask
			  --------
			  1011 1 101
  2) off  (&) --> 1011 1 101 = x
                & 1111 0 111 = ~(mask)
			      -----------
			      1011 0 101
  3) update  (^) --> 1011 0 101 = x
                   ^ 0000 1 000 = mask
			         ----------
			         1011 1 101
  4) check  (&) --> 1011 1 101 = x
                  & 0000 1 000 = mask
			        -----------
			        0000 1 000

	// Addition and Substraction on binary num:
  1.Addition:
   cout<<"Addition on Binary num formate :"<<9+3<<endl;

  carry 1 1 
	  1 0 0 1 = 9
	+ 0 0 1 1 = 3
	 ---------
	  1 1 2 2 = [2 bin-> 1 0,1 bin-> 1 ] 
	  1 1 0 0 = 12

  2.Substraction:
   cout<<"Substarction on Binary num formate :"<<9+(~(3)+1)<<endl;
   
	  1 0 0 1 = 9       9-3=6
	- 0 0 1 1 = 3 ----->2's compliment of 0011 is 1100 and add 1 on it
	 ---------          =1101= (-3)
car..1    1 
   ...1 0 0 1 =  9       9+(-3)=6
 + ...1 1 0 1 = (-3) ----->2's compliment is invert of (31)...0011 is (31)...11100 and add 1 on it
	 ---------          =1101
	  2 1 1 2 = [2 bin-> 1 0,1 bin-> 1 ] 
	0 0 1 1 0 = 6
*/
//   get bit(0,1) at perticular postion(i): 1101
int get_Bit(int num,int i)// chek
  {
	  
	  return ((1 << i) & num)!=0?  1: 0;
  }
  int set_Bit(int num, int i)// on
  {
	  return (1 << i) | num; // 0001
							 //  0010 | 1101 = 1111
  }
  int clear_Bit(int num, int i)// off
  {
	  return ~(1 << i) & num; // 0001
							  //  ~0100 = 1011 =1011 &1101 = 1001
  }
  int update_Bit(int num, int i) //used xor(^)
  {
	  // update = clear + set
	//   int mask = (~(1 << i) & num); // clear 1101 =13
	//   return (1 << i) | mask;		// set 0001 = ~0010 = 1101 =1101 & 1101

	return ((1<<i)^num);
  }									// 0010 =0010 |1101 =1001
  int Multi_by_2(int num)
  {
	  return num << 1;
  }
  int Divid_by_2(int num)
  {
	  return num >> 1;
  }
  void isEvenOrOdd(int num)
  {
	  if ((num & 1) == 0)
		  printf("It is Even Number.\n");
	  else
		  printf("it is Odd Number.\n");
  }
  void swap(int n1, int n2)
  {
	  int a = n1 ^ n2;
	  int b = a ^ n2; // 5
	  a = a ^ b;	  //20
	  cout << "a = " << a << endl;
	  cout << "b = " << b << endl;
  }
  int main()

  { //B bits Basic Operation:
	  short b = 12;
	  cout << (b >> 2)<<endl;
	  cout << get_Bit(13, 1) << endl;
	  cout << set_Bit(13, 1) << endl;
	  cout << clear_Bit(13, 2) << endl;
	  cout << update_Bit(13, 2) << endl;
	  cout << Multi_by_2(15) << endl;
	  cout << Divid_by_2(15) << endl;

	  isEvenOrOdd(21);
	  swap(5, 20);
	  return 0;
  }