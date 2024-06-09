// WAP to insert an element in an array

#include <stdio.h>

int main()
{
  int size, item, index;

  printf("Enter the size of the array :");
  scanf("%d", &size);

  int arr[size];

  printf("Enter array elements : ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Printing the original array
  printf("Before insertion : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  // Scanning the element
  printf("\nEnter the element to insert : ");
  scanf("%d", &item);

  // Scanning the index
  printf("Enter the index where you want to add : ");
  scanf("%d", &index);

  size++;

  // shift elements forward
  for (int i = size - 1; i >= index; i--)
    arr[i] = arr[i - 1];

  // insert x at pos
  arr[index] = item;

  // Printing the updated array
  printf("\nAfter insertion : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
