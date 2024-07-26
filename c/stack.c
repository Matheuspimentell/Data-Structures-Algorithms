#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
} Node;

void unstack(Node** stack_head)
{
	if (stack_head == NULL)
	{
		return;
	}

	Node* tmp = *stack_head;
	*stack_head = (*stack_head)->next;

	free(tmp);

	return;
}

void stack(int data, Node** stack_head)
{
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = *stack_head;
	*stack_head = new_node;
}

int main(int argc, char **argv)
{
	Node* my_stack = NULL;
  for (int i = 1; i < argc; i++)
  {
 	 	stack(atoi(argv[i]), &my_stack);
  }

  while(my_stack != NULL)
  {
  	printf("value: %d\n", my_stack->data);
   	unstack(&my_stack);
  }

  return 0;
}
