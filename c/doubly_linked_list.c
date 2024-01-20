#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
  struct Node* previous;
} Node;

int main(int argc, char const *argv[])
{
  Node *head = NULL;
  head = (Node *)malloc(sizeof(Node));

  if (head == NULL)
  {
    return 1;
  }

  Node *current = NULL;
  current = head;
  current->previous = NULL;

  for (int i = 0; i < 10; i++)
  {
    int value = i + 1;
    current->data = value;
    current->next = (Node *) malloc(sizeof(Node));
    current->next->next = NULL;
    current->next->previous = current;
    current = current->next;
  }

  current = head;
  while (current->next != NULL)
  {
    if (current->previous != NULL)
    {
      printf("Value: %d | Previous Item: %d | Next Item: %d\n", current->data, current->previous->data, current->next->data);
    } 
    else 
    {
      printf("Value: %d | Next Item: %d\n", current->data, current->next->data);
    }
    current = current->next;
  }

  free(head);
  free(current);
  return 0;
}
