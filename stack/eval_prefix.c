#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct Stack
{
  int data[MAX];
  int top;
} Stack;

void initialize(Stack *s)
{
  s->top = -1;
}

int isEmpty(Stack *s)
{
  return s->top == -1;
}

int isFull(Stack *s)
{
  return s->top == MAX - 1;
}

void push(Stack *s, int value)
{
  if (isFull(s))
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  else
  {
    s->data[++(s->top)] = value;
  }
}

int pop(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  else
  {
    return s->data[(s->top)--];
  }
}

int evaluatePrefix(char *expression)
{
  Stack s;
  initialize(&s);
  int length = strlen(expression);

  for (int i = length - 1; i >= 0; i--)
  {
    if (isdigit(expression[i]))
    {
      push(&s, expression[i] - '0');
    }

    else
    {
      int val1 = pop(&s);
      int val2 = pop(&s);
      switch (expression[i])
      {
      case '+':
        push(&s, val1 + val2);
        break;
      case '-':
        push(&s, val1 - val2);
        break;
      case '*':
        push(&s, val1 * val2);
        break;
      case '/':
        if (val2 != 0)
          push(&s, val1 / val2);
        else
        {
          printf("Error: Division by zero\n");
          exit(1);
        }
        break;
      case '^':
        push(&s, pow(val1, val2));
        break;
      default:
        printf("Invalid operator encountered: %c\n", expression[i]);
        exit(1);
      }
    }
  }

  return pop(&s);
}

int main()
{
  char expression[MAX];

  printf("Enter a prefix expression: ");
  scanf("%s", expression);

  int result = evaluatePrefix(expression);
  printf("The result of the prefix expression is: %d\n", result);

  return 0;
}
