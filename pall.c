#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the stack
 * @line_number: current line number
 * @arg: argument (not used)
 */
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
