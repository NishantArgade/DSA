#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
private:
    int m;
    int n;
    int num;
    struct Element *ele;

public:
    ~Sparse()
    {
        delete[] ele;
    }
    void Create()
    {
        printf("Enter Dimention : \n");
        scanf("%d%d", &m, &n);
        printf("Number of Non-zero : \n");
        scanf("%d", &num);

        ele = new Element[num];
        printf("Enter Non-zero Element :\n");
        for (int i = 0; i < num; i++)
        {
            scanf("%d%d%d", &ele[i].i, &ele[i].j, &ele[i].x);
        }
    }
    void Display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == ele[k].i && j == ele[k].j)
                {
                    printf("%d ", ele[k++].x);
                }
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }
};
struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->n != s2->n || s1->m != s2->m)
        return NULL;

    sum = new Sparse;
    sum->ele = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        sum->ele[k++] = s2->ele[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}
int main()
{
    /* Sparse Matrix contain less Non-zero Element compare than zero element.
     num =3; 
             0 0 1
    m X n =  3 0 0                     0   1   2
             0 0 4               | i | 1 | 2 | 3 |
            sparse     ele[num]= | j | 3 | 1 | 3 |
                                 | x | 1 | 3 | 4 |                                     */

    struct Sparse s1, s2, *s3;

    s1.Create();
    printf("Displaing of Whole Matrix : \n");
    s1.Display();

    s2.Create();
    printf("Displaing of Whole Matrix : \n");
    s2.Display();

   

    return 0;
}