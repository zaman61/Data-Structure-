// WAP to find biggest and smallest numbers in an array?

#include <stdio.h>
int main()
{
  int size;

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

  int smallest = arr[0];
  int largest = arr[0];

  for (int i = 1; i < size; i++)
  {
    if (arr[i] < smallest)
    {
      smallest = arr[i];
    }

    if (arr[i] > largest)
    {
      largest = arr[i];
    }
  }

  printf("Smallest element : %d \n", smallest);
  printf("Largest element : %d \n", largest);

  return 0;
}
