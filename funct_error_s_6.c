#include "monty.h"

/**
 * er_r_mo - Conveys specific error messages based on distinct error codes.
 * @incorect: Error codes and their corresponding descriptions:
 * (15) ~> The number inside a node is outside ASCII bounds.
 * (19) ~>The provided file cannot be opened or read.
 * (16) ~> The file contains an invalid instruction.
 * (18) ~>  Insufficient memory available for further allocation.
 * (17) ~> The parameter passed to the "push" instruction is not an integer.
 */
void er_r_mo(int incorect, ...)
{
	char *ch;
	int nu_mbr_lnde;
	va_list k;

	va_start(k, incorect);
	if (incorect == 15)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(k, int));
	}
	else if (incorect == 19)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (incorect == 16)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (incorect == 18)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(k, char *));
	}
	else if (incorect == 17)
	{
		nu_mbr_lnde = va_arg(k, int);
		ch = va_arg(k, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", nu_mbr_lnde, ch);
	}
	fre_e_nod_mo();
	exit(EXIT_FAILURE);
}

/**
 * mor_e_er_mo - Manages various error scenarios.
 * @error_code:  Error codes and their corresponding situations:
 * (20) ~> Empty stack encountered during "pint" instruction.
 * (21) ~> Empty stack encountered during "pop" instruction.
 * (22) ~> Stack size insufficient for the intended operation.
 * (23) ~> it will div by the 0 num.
 */
void mor_e_er_mo(int incorect, ...)
{
    va_list k;
    char *ch;
    int nu_mbr_lnde;

    va_start(k, incorect);

    if (incorect == 22)
    {
        nu_mbr_lnde = va_arg(k, unsigned int);
        ch = va_arg(k, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", nu_mbr_lnde, ch);
    }
    else if (incorect == 23)
    {
        fprintf(stderr, "L%d: division by zero\n",
                va_arg(k, unsigned int));
    }
    else if (incorect == 20)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n",
                va_arg(k, int));
    }
    else if (incorect == 21)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n",
                va_arg(k, int));
    }

    fre_e_nod_mo();
    exit(EXIT_FAILURE);
}

/**
 * str_ing_er_mo -  Addresses error situations.
 *
 * @incorrect:  Corresponding error codes and their descriptions:
 * (25) => The nbr within a node falls outside ascii constraints code.
 * (24) ~> The stack is empty.
 */
void str_ing_er_mo(int incorect, ...)
{
    va_list k;
    int nu_mbr_lnde;

    va_start(k, incorect);
    nu_mbr_lnde = va_arg(k, int);
    if (incorect == 24)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", nu_mbr_lnde);
    }
    else if (incorect == 25)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", nu_mbr_lnde);
    }
    fre_e_nod_mo();
    exit(EXIT_FAILURE);
}
