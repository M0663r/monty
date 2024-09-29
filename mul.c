#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the current opcode.
 * @arg: Argument (not used).
 */
void mul(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *temp;
    int product;

    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    product = (*stack)->next->n * (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = product;

    free(temp);
}
