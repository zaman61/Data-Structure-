#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct StackNode
{
  int data;
  struct StackNode *next;
};

// Function to create a new stack node
struct StackNode *createNode(int data)
{
  struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode *top)
{
  return !top;
}

// Function to push an element onto the stack
void push(struct StackNode **top_ref, int data)
{
  struct StackNode *newNode = createNode(data);
  newNode->next = *top_ref;
  *top_ref = newNode;
  printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct StackNode **top_ref)
{
  if (isEmpty(*top_ref))
  {
    printf("Stack underflow\n");
    return -1;
  }
  struct StackNode *temp = *top_ref;
  *top_ref = (*top_ref)->next;
  int popped = temp->data;
  free(temp);
  return popped;
}

// Function to peek the top element of the stack
int peek(struct StackNode *top)
{
  if (isEmpty(top))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return top->data;
}

// Main function to demonstrate stack operations
int main()
{
  struct StackNode *stack = NULL;

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Top element is %d\n", peek(stack));

  printf("%d popped from stack\n", pop(&stack));
  printf("Top element is now %d\n", peek(stack));

  printf("%d popped from stack\n", pop(&stack));
  printf("%d popped from stack\n", pop(&stack));
  printf("Top element is now %d\n", peek(stack));

  return 0;
}
