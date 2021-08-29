
// Greedy method => Follow some procedure to get optimal solution
// Dinamic programming => try all fisible solution and peck up the best one(optimal) solution.

#include <iostream>
using namespace std;

#define Obj 3
int SackSize = 50;
int Sack[Obj];

void Order(float Cost[Obj], float Weights[Obj])
{
    for (int i = 0; i < Obj; i++)
    {
        for (int j = i + 1; j < Obj; j++)
        {
            if ((Cost[i] / Weights[i]) < (Cost[j] / Weights[j]))
            {
                //Swap for arrange in Decreasing order

                float t2 = Cost[i], t3 = Weights[i];

                Cost[i] = Cost[j];
                Cost[j] = t2;

                Weights[i] = Weights[j];
                Weights[j] = t3;
            }
        }
    }
}
void Knapsack_Problem(float Cost[Obj], float Weights[Obj], int SackSize)
{
    float sum = 0, x;
    Order(Cost, Weights);

    for (int i = 0; i < Obj; i++)
    {

        if (SackSize == 0)
            break;

        if (Weights[i] < SackSize)
        {
            sum += Cost[i];
            SackSize = SackSize - Weights[i];
        }
        else
        {
            // Weights[i] = Cost[i];
            //  (sacksize)  = ?x;
            x = (Cost[i] * SackSize) / Weights[i];
            sum += x;
            SackSize = 0;
        }
    }
    cout << "\n\nThe maximum cost with minimum weight element is " << sum;
}

int main()
{
    /*KnapSack Problem (Fraction method):

    Select  items /Objects form set of Objects such that total cost after taking element in a sack is maximun .
    and  with minimum weight(Total weight <= Capacity of Sack).

    //Greedy Approach:
    GAbout(W) = less optimize;
    GAbout(C) = Less optimize
    GAbout(C/W) = More optimize

    Approch:
    According to the Cost/weight Sort Objects in Decreasing Order.
    After that try to put into Sack and Due to Dividable Object some  reaming sack space fill fractional method.(1pem = 10rs so 5pen = ?) 
*/
    float Cost[Obj] = {60, 100, 120};
    float Weights[Obj] = {10, 20, 30};

    Knapsack_Problem(Cost, Weights, SackSize);
    return 0;
}