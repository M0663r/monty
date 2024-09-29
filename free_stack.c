#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
    stack_t *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
