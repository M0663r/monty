#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the bytecode.
 * @arg: The argument for the opcode (an integer to push).
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int num;

    if (arg == NULL || ((num = atoi(arg)) == 0 && strcmp(arg, "0") != 0))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
