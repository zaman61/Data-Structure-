#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a person
struct Person
{
  char name[50];
  int age;
  float salary;
  char address[100];
  struct Person *next;
};

// Function to create a new person node
struct Person *createPerson(char name[], int age, float salary, char address[])
{
  struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
  strcpy(newPerson->name, name);
  newPerson->age = age;
  newPerson->salary = salary;
  strcpy(newPerson->address, address);
  newPerson->next = NULL;
  return newPerson;
}

// Function to add a person at the end of the linked list
void appendPerson(struct Person **head_ref, char name[], int age, float salary, char address[])
{
  struct Person *newPerson = createPerson(name, age, salary, address);
  struct Person *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = newPerson;
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newPerson;
}

// Function to print the person linked list
void printPersons(struct Person *person)
{
  while (person != NULL)
  {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Salary: %.2f\n", person->salary);
    printf("Address: %s\n\n", person->address);
    person = person->next;
  }
}

// Main function
int main()
{
  struct Person *head = NULL;

  appendPerson(&head, "Ali", 30, 55000.50, "123 Khanyar, Srinagar");
  appendPerson(&head, "Basit", 25, 62000.75, "456 Nowpora, Srinagar");
  appendPerson(&head, "Chacha", 40, 75000.00, "789 Lal Chowk, Srinagar");

  printf("Person Linked List:\n");
  printPersons(head);

  return 0;
}
