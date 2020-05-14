#include "monty.h"

/**
 * add - add and collapse top two nodes
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum, tmp1, tmp2;
	stack_t *temp;

	(void)line_number;
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

/**
 * nop - does nothing
 *@stack: linked list, stack used
 *@line_number: line_number of instruction in monty file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
