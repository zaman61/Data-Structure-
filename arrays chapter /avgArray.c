// WAP to average of n numbers in an array?

#include <stdio.h>
int main()
{
  int size;
  float sum = 0.0;
  float avg;

  printf("Enter the size of array : ");
  scanf("%d", &size);

  float arr[size];

  printf("Enter array elements : ");
  for (int i = 0; i < size; i++)
  {
    scanf("%f", &arr[i]);
    sum += arr[i];
  }

  printf("Array elements are : ");
  for (int i = 0; i < size; i++)
  {
    printf("%0.2f ", arr[i]);
  }

  printf("\n");

  avg = sum / size;
  printf("Average : %0.2f", avg);

  return 0;
}
