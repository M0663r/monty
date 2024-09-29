#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {NULL, NULL}
};

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    int read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    FILE *file;
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = custom_getline(&line, &len, file)) != -1)
    {
        char *opcode, *arg;
        line_number++;
        opcode = strtok(line, " \n\t");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        arg = strtok(NULL, " \n\t");

        for (i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number, arg);
                break;
            }
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}
