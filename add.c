#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number of the current opcode.
 */
void add(stack_t **stack, unsigned int line_number, char* arg)
{
    stack_t *temp;
    int sum;

    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = sum;

    free(temp);
}
