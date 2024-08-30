// WAP to convert a string from lower case to upper case?

#include <stdio.h>
#include <string.h>
int main()
{
  char str1[20];
  char str2[20];
  int i = 0;

  printf("Enter string : ");
  gets(str1);

  while (str1[i] != '\0')
  {
    str2[i] = str1[i] - 32;
    i++;
  }

  printf("\nUppercase string is : %s", str2);

  return 0;
}
