#include "monty.h"

int main(int argc, char **argv)
{
FILE *file;
char *line = NULL, *opcode, *arg;
size_t len = 0;
int read;
unsigned int line_number = 0;
stack_t *stack = NULL;
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};
int i;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((read = custom_getline(&line, &len, file)) != -1)
{
line_number++;
opcode = strtok(line, " \n\t");
if (opcode == NULL || opcode[0] == '#')
continue;

arg = strtok(NULL, " \n\t");

for (i = 0; instructions[i].opcode; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(&stack, line_number, arg);
break;
}
}

if (instructions[i].opcode == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}

free(line);
fclose(file);
return (0);
}
