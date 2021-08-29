#include <stdio.h>
#include <stdlib.h>
struct Term
{
    int coeff;
    int exp;
};
struct Polynomial
{
    int n;
    struct Term *Terms;
};
void Create(struct Polynomial *p)
{
    printf("Enter Number of Terms :\n");
    scanf("%d", &p->n);
    p->Terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter Terms :\n");
    for (int i = 0; i < p->n; i++)
        scanf("%d%d", &p->Terms[i].coeff, &p->Terms[i].exp);
}
void Display(struct Polynomial p)
{
    printf("Polynomial Equation is :\n");

    for (int i = 0; i < p.n; i++)
    {
        printf("%d x^%d + ", p.Terms[i].coeff, p.Terms[i].exp);
    }
    printf("\n");
}
struct Polynomial *Add(struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *sum;
    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->Terms = (struct Term *)malloc(p1->n + p2->n * sizeof(struct Term));

    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->Terms[i].exp > p2->Terms[j].exp)
            sum->Terms[k++] = p1->Terms[i++];

        else if (p1->Terms[i].exp < p2->Terms[j].exp)
            sum->Terms[k++] = p2->Terms[j++];
        else
        {
            sum->Terms[k].exp = p1->Terms[i].exp;
            sum->Terms[k++].coeff = p1->Terms[i++].coeff + p2->Terms[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->Terms[k++] = p1->Terms[i];
    for (; j < p2->n; j++)
        sum->Terms[k++] = p2->Terms[j];
    sum->n = k;
    return sum;
}
int main()
{ /*
    Polynomial eq:

     a x^4 + b x^2 + c x^1 + d ------(x^0 = 1)

    a,b,c,d = coefficient
    4,2,1,0 = exponent

    no of terms(n) = 4 ;

               | ind  |0 |1 |2 |3 |       
     Term[n] = | coeff|a |b |c |d |
               | exp  |4 |2 |1 |0 |
                                                           */
    struct Polynomial p1, p2, *p3;

    printf("Polynomial eq1 :\n");
    Create(&p1);
    Display(p1);
    printf("Polynomial eq2  :\n");
    Create(&p2);
    Display(p2);

    printf("After Add eq1 and eq2 Polynomial eq3 is :\n");
    p3 = Add(&p1, &p2);
    Display(*p3);

    return 0;
}