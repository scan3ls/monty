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


/**
 * sub - subtracts top element of teh stack from the second top element
 *@stack: list
 *@line_number: line_number of instruction in monty file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp1, tmp2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;
	result = tmp2 - tmp1;

	(*stack)->next->n = result;
	temp = *stack;
	*stack =  (*stack)->next;
	free(temp);
}

/**
 * mdiv - divides the second top element of the stack by the top element
 *@stack: stack used
 *@line_number: line_number of instruction from monty file
 */

void mdiv(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp1, tmp2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;
	result = tmp2 / tmp1;
	(*stack)->next->n = result;

	temp = *stack;
	(*stack) = (*stack)->next;
	free(temp);
}

/**
 * mmul - multiplies the second top element of the stack with the top element
 *@stack: stack used
 *@line_number: line number of instuction in monty file
 */

void mmul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp1, tmp2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;
	result = tmp1 * tmp2;

	(*stack)->next->n = result;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
