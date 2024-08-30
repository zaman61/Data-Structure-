#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
  char name[50];
  int rollNumber;
  float marks;
  struct Student *next;
};

struct Student *createStudent(char name[], int rollNumber, float marks)
{
  struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
  strcpy(newStudent->name, name);
  newStudent->rollNumber = rollNumber;
  newStudent->marks = marks;
  newStudent->next = NULL;
  return newStudent;
}

void appendStudent(struct Student **head_ref, char name[], int rollNumber, float marks)
{
  struct Student *newStudent = createStudent(name, rollNumber, marks);
  struct Student *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newStudent;
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newStudent;
}

void printStudents(struct Student *student)
{
  while (student != NULL)
  {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n\n", student->marks);
    student = student->next;
  }
}

int main()
{
  struct Student *head = NULL;

  appendStudent(&head, "Ali", 1, 85.5);
  appendStudent(&head, "Basit", 2, 90.0);
  appendStudent(&head, "Abid", 3, 78.5);

  printf("Student Linked List:\n");
  printStudents(head);

  return 0;
}
