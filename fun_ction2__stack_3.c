#include "monty.h"

/**
 * no_p_mo -  Performs no action.
 * @pile:  Double pointer referencing the pile's top node.
 * @n_ln: Integer denoting the opcode's line number.
 */
void no_p_mo(stack_t **pile, unsigned int n_ln)
{
    (void)pile;
    (void)n_ln;
}

/**
 * swa_p_no_mo -  Interchanges the top two elements within the pile.
 * @pile: Double pointer referencing the pile's uppermost item.
 * @n_ln:  Integer signifying the opcode's line number.
 */
void swa_p_no_mo(stack_t **pile, unsigned int n_ln)
{
    stack_t *Nouv;

    if (*pile == NULL || pile == NULL || (*pile)->next == NULL)
        mor_e_er_mo(8, n_ln, "swap");
    Nouv = (*pile)->next;
    (*pile)->next = Nouv->next;
    if (Nouv->next != NULL)
        Nouv->next->prev = *pile;
    Nouv->next = *pile;
    (*pile)->prev = Nouv;
    Nouv->prev = NULL;
    *pile = Nouv;
}

/**
 * add_nod_mo - Merges the uppermost two elements in the pile.
 * @pile:  Double pointer referencing the pile's highest node.
 * @n_ln:  Integer indicating the opcode's line number.
 */
void add_nod_mo(stack_t **pile, unsigned int n_ln)
{
    int result_sm;

    if ((*pile)->next == NULL || pile == NULL || *pile == NULL)

        mor_e_er_mo(8, n_ln, "add");

    (*pile) = (*pile)->next;
    result_sm = (*pile)->prev->n + (*pile)->n;

    (*pile)->n = result_sm;

    free((*pile)->prev);
    (*pile)->prev = NULL;
}

/**
 * sub_nod_mo -  Computes the difference between the top two pile elements.
 * @pile: Double pointer referencing the pile's uppermost node.
 * @n_ln: Integer indicating the opcode's line number.
 */
void sub_nod_mo(stack_t **pile, unsigned int n_ln)
{
    int result_sm;

    if ((*pile)->next == NULL || pile == NULL || *pile == NULL)
        mor_e_er_mo(8, n_ln, "sub");

    (*pile) = (*pile)->next;
    result_sm = (*pile)->n - (*pile)->prev->n;
    (*pile)->n = result_sm;
    free((*pile)->prev);
    (*pile)->prev = NULL;
}

/**
 * div_nod_mo - Calculates the quotient of the top two pile elements.
 * @pile:  Double pointer referencing the pile's uppermost node.
 * @n_ln: Integer indicating the opcode's line number.
 */
void div_nod_mo(stack_t **pile, unsigned int n_ln)
{
    int result_sm;

    if ((*pile)->next == NULL || pile == NULL || *pile == NULL)
        mor_e_er_mo(8, n_ln, "div");

    if ((*pile)->n == 0)
        mor_e_er_mo(9, n_ln);
    (*pile) = (*pile)->next;

    result_sm = (*pile)->n / (*pile)->prev->n;


    (*pile)->n = result_sm;

    free((*pile)->prev);

    (*pile)->prev = NULL;
}
