#include <stdio.h>
int main()
{
  int size, item, index, notFound = 0;

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

  // Deleting the element
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == item)
    {
      index = i;
      for (int i = index; i < size; i++)
      {
        arr[i] = arr[i + 1];
        notFound = 1;
      }
    }
  }

  // Checking if the element is present in the arary or not
  if (notFound == 0)
  {
    printf("Element not found");
  }
  else
  {
    size -= 1;
    printf("\nAfter deletion : ");
    for (int i = 0; i < size; i++)
    {
      printf("%d ", arr[i]);
    }
  }

  return 0;
}
