#include <stdio.h>
#include <stdlib.h>

void create();
void show();
void reverse();

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL, *tail = NULL;

int main()
{
  create();
  show();
  reverse();
  printf("After reverse\n");
  show();
  return 0;
}

void create()
{
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
      printf("Memory allocation failed\n");
      exit(1);
    }

    printf("Enter the %d data: ", i + 1);
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (head == NULL)
    {
      head = temp;
      tail = temp;
      temp->prev = NULL;
    }
    else
    {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }
}

void reverse()
{
  struct node *temp = head;
  struct node *trav = NULL;
  while (temp != NULL)
  {
    trav = temp->next;
    temp->next = temp->prev;
    temp->prev = trav;
    temp = temp->prev;
  }
  head = tail;
  temp = head;
}

void show()
{
  struct node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
