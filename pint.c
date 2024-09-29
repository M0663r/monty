#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number
 * @arg: argument (not used)
 */
void pint(stack_t **stack, unsigned int line_number, char *arg)
{
    (void)arg;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
