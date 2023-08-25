#include "monty.h"


/**
 * main -  starting point
 * @argc: count of parameteres
 * @argv: list or number of parameters
 * Return: gives us 0 all the time
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fi_lle_op_mo(argv[1]);
	fre_e_nod_mo();

	return (0);
}

/**
 * cre_ate_nod_mo - Generates a new case.
 * @x: Value to be stored in the node.
 * Return: If successful, a pointer to the node; otherwise, NULL.
 */
stack_t *cre_ate_nod_mo(int x)
{
	stack_t *case = NULL;

	case = (stack_t *)malloc(sizeof(stack_t));
	if (case == NULL)
		er_r_mo(16);
	case->next = NULL;

	case->prev = NULL;

	case->n = x;
	return (case);
}

/**
 * fre_e_nod_mo -  Deallocates nodes within the stack.
 */
void fre_e_nod_mo(void)
{
	stack_t *head = NULL;
	stack_t *p;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

/**
 * add_to_qu_mo - Inserts a node into the queue.
 * @item:  new item case pointer.
 * @val_ln: Line number associated with the opcode.
 */
void add_to_qu_mo(stack_t **item, __attribute__((unused)) unsigned int val_ln)
{
	stack_t *head = NULL;
	stack_t *temp;

	if (*item == NULL || item == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *item;
		return;
	}
	temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *item;
	(*item)->prev = temp;
}
