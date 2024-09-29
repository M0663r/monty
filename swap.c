#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number
 * @arg: argument (not used)
 */
void swap(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *first, *second;

    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    first->next = second->next;
    first->prev = second;
    if (second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    *stack = second;
}
