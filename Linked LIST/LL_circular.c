#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void appendNode(struct Node **head_ref, int data)
{
  struct Node *newNode = createNode(data);
  struct Node *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newNode;
    newNode->next = newNode;
    return;
  }

  while (last->next != *head_ref)
  {
    last = last->next;
  }

  last->next = newNode;
  newNode->next = *head_ref;
}

void printList(struct Node *head)
{
  struct Node *temp = head;

  if (head != NULL)
  {
    do
    {
      printf("%d ", temp->data);
      temp = temp->next;
    } while (temp != head);
  }
  printf("\n");
}

int main()
{
  struct Node *head = NULL;

  appendNode(&head, 10);
  appendNode(&head, 20);
  appendNode(&head, 30);
  appendNode(&head, 40);

  printf("Circular Linked List:\n");
  printList(head);

  return 0;
}
