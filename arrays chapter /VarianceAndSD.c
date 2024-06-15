// WAP to Variance and Standard Deviation of n numbers in an array?

#include <stdio.h>
#include <math.h>

int main()
{
  int size;
  float sum;
  float avg, tempSum = 0, variance, sd;

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
  printf("Average : %0.2f\n", avg);

  for (int k = 0; k < size; k++)
  {
    tempSum = tempSum + (avg - arr[k]) * (avg - arr[k]);
  }

  variance = tempSum / size;
  printf("Variance : %0.2f\n", variance);

  sd = sqrt(variance);
  printf("Standard Deviation : %0.2f\n", sd);

  return 0;
}
