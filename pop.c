#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number
 * @arg: argument (not used)
 */
void pop(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *temp;

    (void)arg;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}
