#include "monty.h"
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void pchar(stack_t **stack, unsigned int line_no)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *h;
	(void)line_no;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
  *rotl- rotates the stack to the top
  *@stack: stack head
  *@line_no: line_number
  *Return: no return
 */
void rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_no)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}

/**
  *rotr- rotates the stack to the bottom
  *@stack: stack head
  *@line_no: line_number
  *Return: no return
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_no)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
