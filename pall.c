#include "monty.h"

void pall(stack_t **stack, unsigned int line_number, char *arg)
{
stack_t *current = *stack;
(void)line_number;
(void)arg;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
