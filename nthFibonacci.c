// WAP to print nth term fibonacci series using recursion?

#include <stdio.h>

int fib(int n)
{
  if (n == 1 || n == 2)
  {
    return 1;
  }
  else
  {
    return fib(n - 1) + fib(n - 2);
  }
}

int main()
{
  int n;
  printf("Enter the term of fibonacci you want : ");
  scanf("%d", &n);

  int f = fib(n);

  printf("%dth term of the fibonacci series is %d ", n, f);

  return 0;
}
