// WAP to delete all occurrences of a element in an array

#include <stdio.h>
int main()
{
  int size, item, notFound = 0;

  printf("Enter the size of the array :");
  scanf("%d", &size);

  int arr[size];

  // Scanning array elements from the user
  printf("Enter array elements : ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Before deletion : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\nEnter the element to delete : ");
  scanf("%d", &item);

  // Logic for deletion in array

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == item)
    {
      for (int j = i + 1; j < size; j++)
      {
        arr[j - 1] = arr[j];
        notFound = 1;
      }
      i--;
      size--;
    }
  }

  // Checking if the element is not present in the array
  if (notFound == 0)
  {
    printf("Element not found.");
  }
  else
  {
    // Printing the array
    printf("\nAfter deletion : ");
    for (int i = 0; i < size; i++)
    {
      printf("%d ", arr[i]);
    }
  }

  return 0;
}
