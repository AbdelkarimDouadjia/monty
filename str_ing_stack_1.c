#include "monty.h"

/**
 * pri_nt_ch_mo - Outputs the ASCII representation.
 * @pill: Double pointer referencing the stack's top node.
 * @numb_lin: Integer indicating the opcode's line number.
 */
void pri_nt_ch_mo(stack_t **pill, unsigned int numb_lin)
{
	int g;

	if (pill == NULL || *pill == NULL)
		str_ing_er_mo(24, numb_lin);

	g = (*pill)->n;
	if (g > 127 || g <= 0)
		str_ing_er_mo(25, numb_lin);
	printf("%c\n", g);
}

/**
 * pri_nt_st_mo - Displays a stri.
 * @pill:  Double pointer referencing the stack's top node.
 * @ln_numb:  Integer indicating the opcode's line number.
 */
void pri_nt_st_mo(stack_t **pill, __attribute__((unused)) unsigned int ln_numb)
{
	int g;
	stack_t *temp;

	if (pill == NULL || *pill == NULL)
	{
		printf("\n");
		return;
	}

	temp = *pill;
	while (temp != NULL)
	{
		g = temp->n;
		if (g > 127 || g <= 0)
			break;
		printf("%c", g);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rot_l_mo -  Moves the initial stack node to the end through rotation.
 * @pill: Double pointer referencing the stack's uppermost node.
 * @l_n_numb: Integer denoting the opcode's line number.
 */
void rot_l_mo(stack_t **pill, __attribute__((unused)) unsigned int l_n_numb)
{
	stack_t *temp;

	if (pill == NULL || *pill == NULL || (*pill)->next == NULL)
		return;

	temp = *pill;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *pill;
	(*pill)->prev = temp;
	*pill = (*pill)->next;

	(*pill)->prev->next = NULL;

	(*pill)->prev = NULL;
}

/**
 * rot_r_mo - Shifts the final stack node to the beginning.
 * @pile: Double pointer referencing the stack's uppermost node.
 * @l_n_numb:  Integer indicating the opcode's line number.
 */
void rot_r_mo(stack_t **pile, __attribute__((unused)) unsigned int l_n_numb)
{
	stack_t *temp;

	if ((*pile)->next == NULL || *pile == NULL || pile == NULL)
		return;

	temp = *pile;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *pile;
	temp->prev->next = NULL;

	temp->prev = NULL;

	(*pile)->prev = temp;
	(*pile) = temp;
}
