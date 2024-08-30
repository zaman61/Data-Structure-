#include <stdio.h>
#include <stdlib.h>

int insert();
void sum_avg(int n);
void free_ll();

struct numbers
{
  int data;
  struct numbers *next;
};

struct numbers *head = NULL, *tail = NULL;

int main()
{
  int a = insert();
  sum_avg(a);
  free_ll();
  return 0;
}

int insert()
{
  int n;
  printf("Enter the number of data entries: ");
  scanf("%d", &n);
  struct numbers *temp;
  for (int i = 0; i < n; i++)
  {
    temp = (struct numbers *)malloc(sizeof(struct numbers));
    printf("Enter the %d data: ", i + 1);
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
      head = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }
  return n;
}

void sum_avg(int n)
{
  struct numbers *temp;
  temp = head;
  int sum = 0;
  while (temp != NULL)
  {
    sum += temp->data;
    temp = temp->next;
  }
  printf("Sum = %d\nAverage = %.3f\n", sum, (float)sum / n);
}

void free_ll()
{
  struct numbers *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
  tail = NULL;
}
