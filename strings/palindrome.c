#include <stdio.h>
#include <string.h>

int main()
{
  int len, i;
  char s[10];
  int length, flag = 0;

  printf("Enter string : ");
  scanf("%s", s);

  length = strlen(s);

  for (int i = 0; i < length / 2; i++)
  {
    if (s[i] != s[length - i - 1])
    {
      flag = 1; // not a palindrome
      break;
    }
  }

  if (flag)
  {
    printf("%s is not a palindrome", s);
  }
  else
  {
    printf("%s is a palindrome", s);
  }

  return 0;
}
