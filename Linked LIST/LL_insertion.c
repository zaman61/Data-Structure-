#include <stdio.h>
#include <stdlib.h>

void create();
void insert();
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
  insert();
  view();
  return 0;
}

void create()
{
  struct node *temp;
  int n;
  printf("Enter the total number of data: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
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
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }
}

void insert()
{
  struct node *temp = head;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  if (new_node == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  int item, ch;
  printf("for element to be inserted before ist data, enter 1 else 2: ");
  scanf("%d", &ch);
  if (ch == 1)
  {
    printf("Enter the element to be inserted: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
  }
  else
  {
    printf("Enter the element to be inserted and the element before it: ");
    scanf("%d%d", &new_node->data, &item);
    while (temp->data != item)
      temp = temp->next;
    if (temp->data == item)
    {
      new_node->next = temp->next;
      temp->next = new_node;
    }
    else
    {
      printf("item not present\n");
      free(new_node);
      return;
    }
  }
}

void view()
{
  struct node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
