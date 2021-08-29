#include <stdio.h>

// recurion func for fibbonacci series (Memoization i.e store result) :
// TC : O ( n*n) Store more Activation record.
int rfib(int n)
{
    if (n <= 1)
        return n;
    else
        return rfib(n - 2) + rfib(n - 1);
}
// OR  TC : O(n)//
int fib1(int n)
{

    int t0 = 0, t1 = 1, s = 0;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
   
    }

    return s;
}

// recurion func for fibbonacci series (Memoization i.e store result) :
// TC : O ( n) store less required Activation Record .
int f[50];
int mfib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = mfib(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = mfib(n - 1);

        return f[n - 2] + f[n - 1];
    }
}
int main()
{
    for (int i = 0; i < 50; i++)
    {
        f[i] = -1;
    }

    printf("using simple recur Fibonacci series is : %d\n", rfib(2));
    printf("using simple logic Fibonacci seriesl is : %d\n", fib1(3));
    printf("using memoization Fibonacci seriesl is : %d\n", mfib(4));
    return 0;
}