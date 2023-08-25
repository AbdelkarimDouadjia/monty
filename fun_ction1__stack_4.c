#include "monty.h"


/**
 * pri_nt_to_mo - Shows the uppermost node in the pile.
 * @pile: Double pointer referencing the pile's highest node.
 * @n_ln:  Integer indicating the opcode's line number.
 */
void pri_nt_to_mo(stack_t **pile, unsigned int n_ln)
{
	if (*pile == NULL || pile == NULL)
		mor_e_er_mo(20, n_ln);

	printf("%d\n", (*pile)->n);
}

/**
 * pri_nt_st_mo - Presents the stack's contents.
 * @pile: Double pointer referencing the pile's uppermost node.
 * @n_ln:  Line number associated with the opcode.
 */
void pri_nt_st_mo(stack_t **pile, unsigned int n_ln)
{
	stack_t *p;
	(void)n_ln;

	if (pile == NULL)
		exit(EXIT_FAILURE);

	p = *pile;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * add_to_st_mo -  Appends a node to the stack.
 * @Nouv:  pointo the new produced item.
 * @n_ln:  Integer denoting the opcode's line number.
 */
void add_to_st_mo(stack_t **Nouv, __attribute__((unused)) unsigned int n_ln)
{
	stack_t *p;

	if (*Nouv == NULL || Nouv == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *Nouv;
		return;
	}
	p = head;

	head = *Nouv;
	head->next = p;

	p->prev = head;
}

/**
 * pop_to_mo - Eliminates the uppermost node in the pile.
 * @pile: Double pointer referencing the pile's highest item.
 * @n_ln: Integer denoting the opcode's line number.
 */
void pop_to_mo(stack_t **pile, unsigned int n_ln)
{
	stack_t *p;

	if (pile == NULL || *pile == NULL)
		mor_e_er_mo(21, n_ln);

	p = *pile;
	*pile = p->next;

	if (*pile != NULL)
		(*pile)->prev = NULL;

	free(p);
}
