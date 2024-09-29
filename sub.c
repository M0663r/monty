#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the current opcode.
 * @arg: Argument (not used).
 */
void sub(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *temp;
    int difference;

    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    difference = (*stack)->next->n - (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = difference;
    free(temp);
}
