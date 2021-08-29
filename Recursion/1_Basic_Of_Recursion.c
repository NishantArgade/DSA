#include <stdio.h>

// perform Operation on Calling Time in Recursion :
void func1(int n)
{
  if (n > 0)
  {
    printf("%d ", n * 10); // calling time Operaton.
    func1(n - 1);
  }
}
// perform Operation on Returning Time in Recursion :
void func2(int n)
{
  if (n > 0)
  {
    func2(n - 1);
    printf("%d ", n * 10); // returning time Operaton.
  }
}

int func3(int n)
{
  static int x = 0; // initialy x=0
  if (n > 0)
  {
    x++; // After increment x = 1,2,3,4,5 .in last x=[5]
    return func3(n - 1) + x;
  }
  return 0;
}
// Global variables in Recursion :
int g = 0; // initialy g = 0
int func4(int n)
{
  if (n > 0)
  {
    g++; // After increment g = 1,2,3,4,5 .in last g=[5]
    return func4(n - 1) + g;
  }
  return 0;
}
int main()
{
  // calling time and Returning time Recursion:
  printf("calling time:\n");
  func1(5);
  printf("\nReturning time:\n");
  func2(5);

  // Static and Global varibles can have only one copy(allocate one block memory only) :
  int ans3 = func3(5);
  printf("\nResult : %d", ans3);

  int ans4 = func4(5);
  printf("\nResult : %d", ans4);

  return 0;
}