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

void insertAtBeginning(struct Node **head_ref, int data)
{
  struct Node *newNode = createNode(data);
  struct Node *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newNode;
    newNode->next = newNode;
  }
  else
  {
    while (last->next != *head_ref)
    {
      last = last->next;
    }
    newNode->next = *head_ref;
    last->next = newNode;
    *head_ref = newNode;
  }
}

void insertAtEnd(struct Node **head_ref, int data)
{
  struct Node *newNode = createNode(data);
  struct Node *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newNode;
    newNode->next = newNode;
  }
  else
  {
    while (last->next != *head_ref)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->next = *head_ref;
  }
}

void insertAfter(struct Node *prev_node, int data)
{
  if (prev_node == NULL)
  {
    printf("The given previous node cannot be NULL\n");
    return;
  }
  struct Node *newNode = createNode(data);
  newNode->next = prev_node->next;
  prev_node->next = newNode;
}

void deleteNode(struct Node **head_ref, int key)
{
  if (*head_ref == NULL)
    return;

  struct Node *temp = *head_ref, *prev;

  if (temp->data == key && temp->next == *head_ref)
  {
    *head_ref = NULL;
    free(temp);
    return;
  }

  if (temp->data == key)
  {
    while (temp->next != *head_ref)
    {
      temp = temp->next;
    }
    temp->next = (*head_ref)->next;
    free(*head_ref);
    *head_ref = temp->next;
    return;
  }

  while (temp->next != *head_ref && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp->data != key)
  {
    printf("Key not found in the list\n");
    return;
  }

  prev->next = temp->next;
  free(temp);
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

  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtBeginning(&head, 5);
  insertAfter(head->next, 25);

  printf("Circular Linked List after insertions:\n");
  printList(head);

  deleteNode(&head, 5);
  deleteNode(&head, 25);

  printf("Circular Linked List after deletions:\n");
  printList(head);

  return 0;
}
