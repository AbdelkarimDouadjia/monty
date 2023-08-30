#include "monty.h"
/**
  *sub- sustration
  *@stack: stack head
  *@line_no: line_number
  *Return: no return
 */
void sub(stack_t **stack, unsigned int line_no)
{
	stack_t *aux;
	int sus, nodes;

	aux = *stack;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stack = aux->next;
	free(aux);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void mod(stack_t **stack, unsigned int line_no)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}

/**
 * div - divides the top two elements of the stack.
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void divs(stack_t **stack, unsigned int line_no)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
