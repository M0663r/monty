#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the current opcode.
 * @arg: Argument (not used).
 */
void _div(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *temp;
    int result;

    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n / (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = result;

    free(temp);
}
