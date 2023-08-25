#include "monty.h"
stack_t *tete = NULL;

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
    return 0;
}

/**
 * cre_ate_nod_mo - Generates a new case.
 * @x: Value to be stored in the node.
 * Return: If successful, a pointer to the node; otherwise, NULL.
 */
stack_t *cre_ate_nod_mo(int n)
{
    stack_t *case;

    case = malloc(sizeof(stack_t));
    if (case == NULL)
        er_r_mo(4);
    case->next = NULL;
    case->prev = NULL;
    case->n = x;
    return (case);
}

/**
 * fre_e_nod_mo -  Deallocates nodes within the stack.
 */
void fre_e_nod_mo()
{
    stack_t *temp;

    if (tete == NULL)
        return;

    while (tete != NULL)
    {
        temp = tete;
        tete = tete->next;
        free(temp);
    }
}

/**
 * add_to_qu_mo - Inserts a node into the queue.
 * @item:  new item case pointer.
 * @val_ln: Line number associated with the opcode.
 */
void add_to_qu_mo(stack_t **item, __attribute__((unused)) unsigned int val_ln)
{
    stack_t *temp;

    if (*item == NULL|| item == NULL)
        exit(EXIT_FAILURE);
    if (tete == NULL)
    {
        tete = *item;
        return;
    }
    temp = tete;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *item;
    (*item)->prev = temp;
}
