#include "monty.h"

/**
 * mul_nod_mo -  Computes the product of the top two stack elements.
 * @pile:  Double pointer referencing the stack's uppermost node.
 * @lin_numbr:  Integer indicating the opcode's line number.
 */
void mul_nod_mo(stack_t **pile, unsigned int lin_numbr)
{
	int som;

	if ((*pile)->next == NULL || *pile == NULL || pile == NULL)
		mor_e_er_mo(22, lin_numbr, "mul");

	(*pile) = (*pile)->next;
	som = (*pile)->n * (*pile)->prev->n;
	(*pile)->n = som;

	free((*pile)->prev);

	(*pile)->prev = NULL;
}

/**
 * mod_nod_mo - Calculates the remainder of dividing the top,
 * the two stack elements.
 * @pile: Double pointer referencing the stack's uppermost node.
 * @ln_numbr:  Integer indicating the opcode's line number.
 */
void mod_nod_mo(stack_t **pile, unsigned int ln_numbr)
{
	int some;

	if (*pile == NULL || pile == NULL || (*pile)->next == NULL)
		mor_e_er_mo(22, ln_numbr, "mod");

	if ((*pile)->n == 0)
		mor_e_er_mo(23, ln_numbr);
	(*pile) = (*pile)->next;
	some = (*pile)->n % (*pile)->prev->n;
	(*pile)->n = some;

	free((*pile)->prev);

	(*pile)->prev = NULL;
}
