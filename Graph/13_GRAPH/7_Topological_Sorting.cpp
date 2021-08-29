#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define n 12

void Addedge(vector<int> v[n], int ver, int adj)
{
    v[ver].push_back(adj);
}
void printAdjList(vector<int> v[n])
{
    cout << "Adjecent List is:" << endl;
    for (int ver = 0; ver < n; ver++)
    {
        if (v[ver].size() != 0)
        {
            cout << ver << " --> ";
            for (int i = 0; i < v[ver].size(); i++)
                cout << v[ver][i] << " ";
            cout << endl;
        }
    }
}

void TopologicalSortUtil(vector<int> v[n], int *visited,stack<int> &stk, int start)
{
    // Mark Current vertex as visited . 
    visited[start] = 1; 
   // perform topological sort on each unvisited adjecents of current vertex.
    for (int i = 0; i < v[start].size(); i++)
    {
        int adj = v[start][i];
        if (visited[adj] == 0)
        {
            TopologicalSortUtil(v, visited,stk, adj);
        }
    }
    stk.push(start);// At the Returning time push vertex into stack
}
void TopologicalSort(vector<int> v[n], int start)
{

    stack<int> stk;
    int visited[n];
    memset(visited, 0, sizeof(visited)); //Mark all as Unvisited

    //For Various Component to check is visited or not :
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == 0 )
            TopologicalSortUtil(v, visited,stk, i);
    }
    // Print Satck :
    cout<<"Topological Sorting is :"<<endl;
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{ /* 
  
  Topological Sorting:=> In which sorting is Done such that,parent vertex Always come first before of its childs. 
  TimeComplexcity: O(n^2)  
  SpaceComplexcity: O(n)  

  Advantages :
  1) Steps for Filling Online Form.
  
  real life example:
  1 to 9th--->10th-->12th--->4 year engi--> Mtech

  For That Graph Must be ==>
  Directed Acyclic Graph:

 1)     1 --> 2 --> 3 --> 4 --> 5
        1-6 ->\     \<- 2-8
               6     8
         6-7 ->\     \<- 8-9
                7     9

 2)       10 
            \
            11
              */

    vector<int> v[n];

    Addedge(v, 1, 2);
    Addedge(v, 2, 3);
    Addedge(v, 3, 4);
    Addedge(v, 4, 5);
    Addedge(v, 2, 6);
    Addedge(v, 6, 7);
    Addedge(v, 3, 8);
    Addedge(v, 8, 9);
    Addedge(v, 10, 11);

    printAdjList(v);

    TopologicalSort(v, 1);

    return 0;
}