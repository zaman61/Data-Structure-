// WAP to find product of n numbers in an array?

#include <stdio.h>
int main()
{
  int size, product = 1;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  printf("Enter the array elements: ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
    product *= arr[i];
  }

  printf("Array elements are : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Product of array elements : %d \n", product);

  return 0;
}
