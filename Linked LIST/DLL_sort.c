#include <stdio.h>
#include <stdlib.h>

void create();
void show();
void sort();

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
  sort();
  printf("After sorted\n");
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

void sort()
{
  struct node *temp = NULL;
  struct node *trav;
  int swapped;
  do
  {
    swapped = 0;
    trav = head;

    while (trav->next != temp)
    { // used this so that it does not compare already sorted nodes.
      if (trav->data > trav->next->data)
      {
        int n = trav->data;
        trav->data = trav->next->data;
        trav->next->data = n;
        swapped = 1;
      }
      trav = trav->next;
    }
    temp = trav;
  } while (swapped);
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
