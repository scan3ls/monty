#include "monty.h"

void pushNode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ( params[line_number - 1] == FAILURE)
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
	if (*stack == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack;
		(*stack)->prev = temp;
	}
	*stack = temp;
}

void printNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp1, tmp2;

	if (*stack == NULL || ((*stack)->next == NULL))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stak too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;

	(*stack)->n = tmp2;
	(*stack)->next->n = tmp1;
}
