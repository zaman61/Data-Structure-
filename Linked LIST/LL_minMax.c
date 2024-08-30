#include <stdio.h>
#include <stdlib.h>

void insert();
void min_max();
void free_ll();

struct number
{
  int data;
  struct number *next;
};

struct number *head = NULL, *tail = NULL;

int main()
{
  insert();
  min_max();
  free_ll();
  return 0;
}

void insert()
{
  struct number *temp;
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    temp = (struct number *)malloc(sizeof(struct number));
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
}

void min_max()
{
  struct number *temp;
  temp = head;
  int max = temp->data;
  int min = temp->data;
  while (temp != NULL)
  {
    if (temp->data > max)
      max = temp->data;
    else if (temp->data < min)
      min = temp->data;
    temp = temp->next;
  }
  printf("Maximun = %d\nMinimum = %d\n", max, min);
}

void free_ll()
{
  struct number *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
  tail = NULL;
}
