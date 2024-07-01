#include <stdio.h>

int lev(int n)
{
  if (n == 1 || n == 2 || n == 3)
  {
    return 1;
  }
  else
  {
    return lev(n - 1) + lev(n - 2) + lev(n - 3);
  }
}

int main()
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("%dth term of the lev sequence is %d ", n, lev(n));

  return 0;
}
