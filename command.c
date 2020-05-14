#include "monty.h"

/**
 * getFunc - get function for given opCode
 *@opCode: given opCode
 *
 * Return: function or NULL if not valid
 */

void (*getFunc(char *opCode))(stack_t **, unsigned int)
{
	instruction_t codes[] = {
		{"push", pushNode},
		{"pall", printNodes},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (!(strcmp(opCode, codes[i].opcode)))
		{
			return (codes[i].f);
		}
	}

	return (NULL);
}


/**
 * isValid - check if code and value combination is valid
 *@opCode: given opCode
 *@value: value to check as char
 *
 * Return: 1 if valid, -1 if not valid
 */

int isValid(char *opCode, char value)
{
	if (value == 'a' && (strcmp(opCode, "push") == 0))
		return (-1);
	return (1);
}

/**
 * freeStack - frees a stack
 *@stack: stack to free
 */
void freeStack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	while (stack->next != NULL)
	{
		temp = stack;
		stack = stack->next;
		stack->prev = NULL;
		free(temp);
	}

	free(stack);
}
