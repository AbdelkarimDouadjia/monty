#include "monty.h"
/**
 * addnode - add node to the head stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **stack, int n)
{

	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
/**
* freemem - frees a doubly linked list
* @stack: head of the stack
*/
void freemem(stack_t *stack)
{
	stack_t *aux;

	aux = stack;
	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}
/**
 * queue - prints the top
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void queue(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
/**
 * stack - prints the top
 * @stack: stack head
 * @line_no: line_number
 * Return: no return
*/
void starck(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	bus.lifi = 0;
}

