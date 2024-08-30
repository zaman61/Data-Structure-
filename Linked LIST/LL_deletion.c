#include <stdio.h>
#include <stdlib.h>

void create();
void del();
void view();

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL, *tail = NULL;

int main()
{
  create();
  del();
  view();
  return 0;
}

void create()
{
  int n;
  printf("Enter the total number of data: ");
  scanf("%d", &n);
  struct node *temp;
  for (int i = 0; i < n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
      printf("Memory allocation failed\n");
      exit(1);
    }
    printf("Enter the %d element: ", i + 1);
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

void del()
{
  struct node *temp = head, *trav = NULL;
  int element;
  printf("Enter the element to be deleted: ");
  scanf("%d", &element);

  while (temp != NULL)
  {
    if (temp->data == element)
    {
      if (temp == head)
      {
        head = temp->next;
        free(temp);
        temp = head;
        if (head == NULL)
          tail = NULL;
      }
      else
      {
        trav->next = temp->next;
        if (temp == tail)
          tail = trav;
        free(temp);
        temp = trav->next;
      }
    }
    else
    {
      if (temp != tail)
      {
        trav = temp;
        temp = temp->next;
      }
      else
      {
        printf("Element not found\n");
        return;
      }
    }
  }
}

void view()
{
  struct node *temp = head;
  if (temp == NULL)
    printf("Empty\n");
  else
  {
    while (temp != NULL)
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
