#include "monty.h"
/**
 * push - add node to the stack
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_no)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_no);
			fclose(bus.file);
			free(bus.content);
			freemem(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}

/**
 * pall - prints the stack
 * @stack: stack head
 * @line_no: no used
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *h;
	(void)line_no;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - prints the top
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);

}

/**
 * pop - prints the top
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);

}

/**
 * swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *h = *stack;
	int len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
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
