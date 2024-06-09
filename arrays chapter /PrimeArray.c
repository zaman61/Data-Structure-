// WAP to display only prime numbers in an array?

#include <stdio.h>
int main()
{
  int size, counter;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  printf("Enter the array elements: ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Array elements are : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Prime numbers in the array are : ");

  for (int i = 0; i < size; i++)
  {
    counter = 0;

    for (int j = 2; j < arr[i]; j++)
    {
      if (arr[i] % j == 0)
      {
        counter = 1;
        break;
      }
    }
    if (counter == 0)
    {
      printf("%d ", arr[i]);
    }
  }

  return 0;
}
