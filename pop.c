#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the bytecode file.
 * @arg: The argument for the opcode (not used here).
 */
void pop(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *temp;

    (void)arg;  /* We don't need arg for pop */
    
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    
    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}
