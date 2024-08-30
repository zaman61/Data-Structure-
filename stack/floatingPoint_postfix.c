#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct
{
  int top;
  float items[MAX];
} Stack;

void push(Stack *s, float value);
float pop(Stack *s);
int isEmpty(Stack *s);
float peek(Stack *s);
float stringToFloat(char *str);

float evaluatePostfix(char *expression)
{
  Stack s;
  s.top = -1;
  char buffer[MAX];
  int bufIndex = 0;

  for (int i = 0; expression[i]; i++)
  {
    if (isdigit(expression[i]) || (expression[i] == '.' && isdigit(expression[i + 1])))
    {
      buffer[bufIndex++] = expression[i];
      if (!isdigit(expression[i + 1]) && expression[i + 1] != '.')
      {
        buffer[bufIndex] = '\0';
        push(&s, stringToFloat(buffer));
        bufIndex = 0;
      }
    }
    else if (expression[i] == ' ' || expression[i] == '\t')
    {
      continue;
    }
    else
    {
      float operand2 = pop(&s);
      float operand1 = pop(&s);

      switch (expression[i])
      {
      case '+':
        push(&s, operand1 + operand2);
        break;
      case '-':
        push(&s, operand1 - operand2);
        break;
      case '*':
        push(&s, operand1 * operand2);
        break;
      case '/':
        push(&s, operand1 / operand2);
        break;
      case '^':
        push(&s, powf(operand1, operand2));
        break;
      default:
        printf("Invalid operator: %c\n", expression[i]);
        exit(1);
      }
    }
  }
  return pop(&s);
}

// Push function
void push(Stack *s, float value)
{
  if (s->top == (MAX - 1))
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  s->items[++(s->top)] = value;
}

float pop(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  return s->items[(s->top)--];
}

int isEmpty(Stack *s)
{
  return s->top == -1;
}

// Peek function
float peek(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
    exit(1);
  }
  return s->items[s->top];
}

float stringToFloat(char *str)
{
  return strtof(str, NULL);
}

int main()
{
  char expression[MAX];

  printf("Enter a postfix expression: ");
  fgets(expression, sizeof(expression), stdin);

  size_t len = strlen(expression);
  if (len > 0 && expression[len - 1] == '\n')
  {
    expression[len - 1] = '\0';
  }

  float result = evaluatePostfix(expression);
  printf("The result of the postfix expression is: %.6f\n", result);

  return 0;
}
