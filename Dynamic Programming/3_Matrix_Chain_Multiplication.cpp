#include <iostream>
using namespace std;
#define n 5

void MatrixChainMul(int Dim[n], int MinMuleff[n][n], int ParenDicision[n][n])
{
    int j, t;
    for (int dig = 1; dig < n - 1; dig++)
    {
        for (int i = 1; i < n - dig; i++)
        {
            j = i + dig;
            int min = 999999999;
            for (int k = i; k < j; k++)
            {
                t = MinMuleff[i][k] + MinMuleff[k + 1][j] + Dim[i - 1] * Dim[k] * Dim[j];
                if (t < min)
                {
                    min = t;
                    MinMuleff[i][j] = min;
                    ParenDicision[i][j] = k;
                }
            }
        }
    }
    cout << "\nFor matrix chain Multiplication ,Minimum multiplication effort is " << MinMuleff[1][n - 1] << endl;
    cout << "\nfor that min multiplication effort ,parentheses must be :"<<endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << ParenDicision[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{ /*
  Matrix Multiplication :
  Rules:
  1) Matrix are multiply if and only if when no.column (1'st mat) and no. row(2'nd mat) are Equal.
  2) if two matrix has multiple then reultant will be 
     ex mat 1st= 3X2 mat 2nd = 2X5
       resultant = 3X5

  3)In resultant there are 3X5= 15 elements
    for Obtain each element of resultant we have to two multiplication.similarly for obtain 15 element we have to 15X2 = 30 multiplication.
  
  Q.Multiply chain of matrix give parentheses  to that chain of matrix such that multipliction effort will get reduced. 

         */
    int MinMuleff[n][n] = {
        {0, 1, 2, 3, 4},
        {1, 0, 0, 0, 0},
        {2, 0, 0, 0, 0},
        {3, 0, 0, 0, 0},
        {4, 0, 0, 0, 0},
    };
    int ParenDicision[n][n] = {
        {0, 1, 2, 3, 4},
        {1, 0, 0, 0, 0},
        {2, 0, 0, 0, 0},
        {3, 0, 0, 0, 0},
        {4, 0, 0, 0, 0},
    };
    int Dim[n] = {5, 4, 6, 2, 7};

    MatrixChainMul(Dim, MinMuleff, ParenDicision);
    return 0;
}