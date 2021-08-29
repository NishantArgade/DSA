#include <iostream>
#include <limits.h>
using namespace std;
int findNonRepeatEle(int Arr[], int tn, int tnp1, int tnp2, int n)
{
	for (int i = 0; i < n; i++)
	{
		int cwtn = Arr[i] & tn;
		int cwtnp1 = Arr[i] & tnp1;
		int cwtnp2 = Arr[i] & tnp2;

		tn = tn & (~cwtn); //set as off
		tnp1 = tnp1 | cwtn;// set as On

		tnp1 = tnp1 & (~cwtnp1); //set as off
		tnp2 = tnp2 | cwtnp1;// set as On

		tnp2 = tnp2 & (~cwtnp2); //set as off
		tn = tn | cwtnp2;// set as On
	}
	return tnp1;
}
int main()
{
	int tn = INT_MAX, tnp1 = 0, tnp2 = 0;
	int Arr[] = {12, 12, 12, 23, 45, 67, 23, 67, 45, 23, 67, 45, 10};
	int n = sizeof(Arr) / sizeof(Arr[0]);
	cout << "Non-repeat element is : " << findNonRepeatEle(Arr, tn, tnp1, tnp2, n)<<endl;
	return 0;
}
