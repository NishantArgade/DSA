#include <stdio.h>

// recurion func for Factorization TC : O(n*n) :
int fac(int n)
{
    if (n <= 1)
        return 1;
    return fac(n - 1) * n;
}
// Ex (selection from "n" of r items )Combination Formula: nCr = n! / (n-r)! * r!
// TC = O(n)
int nCr(int n, int r)
{
    int t1 = fac(n),
        t2 = fac(n - r),
        t3 = fac(r);

    return t1 / (t2 * t3);
}
//OR : TC = O(n) Pasculs Trangle
int nCr1(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    return nCr1(n - 1, r - 1) + nCr1(n - 1, r);
}
// Taylor Series :
// Tc O(n*n)
double e(int x, int n)
{
    static int p = 1, f = 1; // allocate one block size memory, i.e size = [1]
    if (n == 0)
        return 1;

    double r;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;

    return r + (p / f);
}
// Optimal Solution
double loop_e(int x, int n)
{
    double s = 1.00;

    for (; n > 0; n--)
    {
        s = (1 + (x / n)) * s;
    }
    return s;
}
// Optimal Solution
double recur_e(int x, int n)
{
    static double s = 1.00;

    if (n == 0)
        return s;

    s = (1 + (x / n)) * s;

    return recur_e(x, n - 1);
}

int main()
{
    printf("%d\n", nCr(5, 2));
    printf("%d\n", nCr1(5, 2));
    printf("\nTaylor Series is : %lf\n", e(2, 1));
    printf("\nTaylor Series is : %lf\n", loop_e(2, 1));
    printf("\nTaylor Series is : %lf\n", recur_e(2, 1));
    return 0;
}