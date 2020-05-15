#include "monty.h"

/**
 * pushNode - Push value to stack
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void pushNode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (params[line_number - 1] == FAILURE)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		dprintf(STDERR_FILENO, "Eror: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = params[line_number - 1];
	temp->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}

/**
 * printNodes - Print all value of a stack
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void printNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("0\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print top of the stack
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove value from the top of a stack
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swap top two values in a stack
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp1, tmp2;

	(void)line_number;
	if (*stack == NULL || ((*stack)->next == NULL))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;

	(*stack)->n = tmp2;
	(*stack)->next->n = tmp1;
}
