#include "monty.h"
/**
 */
void read_file(char *file)
{
	FILE *fp = fopen(file, "r");
	char buffer[1024];
	unsigned int line = 1;
	ssize_t n = 0;
	int flag;
	char *opcode;
	char *item;

	instruction_t funcs[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), fp))
	{
		opcode = strtok(buffer, " \t\n");

		for (n = 0; funcs[n].opcode != NULL; n++)
		{
			if (strcmp(opcode, funcs[n].opcode) == 0)
			{
				flag = 0;
				if (funcs[n].f == push)
				{
					item = strtok(NULL, " \t\n");
					if (item)
					{
						funcs[n].f(&top, atoi(item));
						line++;
					}
					else
					{
						fprintf(stderr,"L%d: usage: push integer", line);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					line++;
					funcs[n].f(&top, line);
				}
				break;
			}
			else
				flag = -1;
		}
		if (flag == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
