#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void appendNode(struct Node **head_ref, int data)
{
  struct Node *newNode = createNode(data);
  struct Node *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newNode;
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newNode;
  newNode->prev = last;
}

void printListForward(struct Node *node)
{
  printf("Doubly Linked List (Forward):\n");
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void printListBackward(struct Node *node)
{
  struct Node *last;

  while (node != NULL)
  {
    last = node;
    node = node->next;
  }

  printf("Doubly Linked List (Backward):\n");
  while (last != NULL)
  {
    printf("%d ", last->data);
    last = last->prev;
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

  printListForward(head);
  printListBackward(head);

  return 0;
}
