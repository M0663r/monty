#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number, char *arg);
void pint(stack_t **stack, unsigned int line_number, char *arg);
void pop(stack_t **stack, unsigned int line_number, char *arg);
void swap(stack_t **stack, unsigned int line_number, char *arg);
void free_stack(stack_t *stack);
int custom_getline(char **lineptr, size_t *n, FILE *stream);
void add(stack_t **stack, unsigned int line_number, char* arg);
void sub(stack_t **stack, unsigned int line_number, char *arg);
void _div(stack_t **stack, unsigned int line_number, char *arg);
void mul(stack_t **stack, unsigned int line_number, char *arg);

#endif /* MONTY_H */
