#include "monty.h"
/**
 */
void push(stack_t **stack, unsigned int line_no)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_no;
	if (new_node == NULL)
	{
		fprintf(stderr,"Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_no;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;
	(void)line_no;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 */
void pint(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 */
void pop(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (*stack)
	{
		stack_t *tmp = *stack;

		printf("%d\n", tmp->n);
		*stack = tmp->next;
		free(tmp);
	}
}

/**
 */
void swap(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (*stack)
	{
		stack_t *tmp;

		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		(tmp->next)->prev = *stack;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp->prev = NULL;
		*stack = tmp;
	}
}
