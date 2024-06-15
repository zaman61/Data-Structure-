// WAP to calculate factorial of a number using recursion?

#include <stdio.h>

int fact(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * (fact(n - 1));
  }
}

int main()
{
  int n, f;
  printf("Enter the number you want factorial of : ");
  scanf("%d", &n);

  f = fact(n);
  printf("Factorial of %d is %d", n, f);

  return 0;
}
