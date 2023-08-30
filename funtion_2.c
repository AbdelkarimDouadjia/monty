#include "monty.h"
/**
 */
void add(stack_t **stack, unsigned int line_no)
{
	int sum = (*stack)->n + ((*stack)->prev)->n;
	(void)line_no;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 */
void nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}
