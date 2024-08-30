#include <stdio.h>
#include <string.h>
int main()
{
  char str[100];
  printf("Enter string : ");
  gets(str);

  printf("Original string : %s\n", str);

  int length = strlen(str);

  for (int i = 0, j = length - 1; i <= j; i++, j--)
  {
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
  }

  printf("Reversed string is : %s", str);

  return 0;
}
