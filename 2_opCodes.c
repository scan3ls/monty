#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	int sum, tmp1, tmp2;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;
	sum = tmp1 + tmp2;

	(*stack)->next->n = sum;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

}

void nop(stack_t **stack, unsigned int line_number)
{

}
