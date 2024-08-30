#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insert();
void var_sd(int);
void free_ll();

struct data
{
  int item;
  struct data *next;
};

struct data *head = NULL, *tail = NULL;

int main()
{
  int a = insert();
  var_sd(a);
  free_ll();
  return 0;
}

int insert()
{
  struct data *temp;
  int n;
  printf("Enter the number of data entries: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    temp = (struct data *)malloc(sizeof(struct data));
    printf("enter %d entry: ", i + 1);
    scanf("%d", &temp->item);
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

void var_sd(int n)
{
  float sum = 0;
  struct data *temp = head;
  while (temp != NULL)
  {
    sum += temp->item;
    temp = temp->next;
  }
  float mean = sum / n;
  temp = head;
  sum = 0;
  while (temp != NULL)
  {
    sum += pow(((temp->item) - mean), 2);
    temp = temp->next;
  }
  float sd = sqrt(sum / n);
  float variance = pow(sd, 2);
  printf("Standard deviation = %.3f\nvariance = %.3f\n", sd, variance);
}

void free_ll()
{
  struct data *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
  tail = NULL;
}
