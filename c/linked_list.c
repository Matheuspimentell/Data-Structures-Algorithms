#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node * nextItem;
} node;

void main(int argc, char * argv[])
{
    node * head = NULL;
    head = (node *) malloc(sizeof(node));
    if (head == NULL)
    {
        return;
    }
    
    node * current = NULL;
    current = head;
    for(int i = 0; i < 10; i++)
    {    
        int value;
        scanf("%d", &value);
        current->value = value;
        current->nextItem = (node *) malloc(sizeof(node));
        current->nextItem->nextItem = NULL;
        current = current->nextItem;
    }
    current = head;

    while(current->nextItem != NULL)
    {
        printf("item value: %d\n", current->value);
        current = current->nextItem;
    }

    
    free(current);
    free(head);
    return;
}
