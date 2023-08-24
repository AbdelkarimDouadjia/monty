#include "monty.h"

/**
 * fi_lle_op_mo - triggers the process of opening a file
 * @file_name: the file namepath to be accessed
 * Return: None
 */

void fi_lle_op_mo(char *nm_fl)
{
	FILE *op = fopen(nm_fl, "r");

	if (nm_fl == NULL || op == NULL)
		err(2, nm_fl);

	rea_d_fi_mo(op);
	fclose(op);
}


/**
 * fi_lle_op_mo - retrieves data from a file
 * @fd:  pointer referring to the file descriptor
 * Return: Nothing
 */

void fi_lle_op_mo(FILE *opr)
{
	int  nm_l_ine,, fo_r_ma = 0;
	char *bfs = NULL;
	size_t len_g = 0;

	for (nm_l_ine = 1; getline(&bfs, &len_g, opr) != -1; nm_l_ine++)
	{
		fo_r_ma = par_se_ln_mo(bfs, nm_l_ine, fo_r_ma);
	}
	free(bfs);
}


/**
 * par_se_ln_mo - Divides each line into tokens to identify
 * the appropriate function to invoke
 * @bfs: line extracted from the file
 * @nm_l_ine:  line number reference
 * @frt: data representation mode. If 0, nodes are treated as a stack.
 * If 1, nodes are treated as a queue.
 * Return: gives us 0 for stack opcode, 1 for queue opcode.
 */

int par_se_ln_mo(char *bfs, int nm_l_ine, int frt)
{
    char *o_pc, *val_l;
    const char *ed = "\n ";

    if (bfs == 0)
        err(4);

    o_pc = strtok(bfs, ed);
    if (o_pc == 0)
        return (frt);
    val_l = strtok(0, ed);

    if (strcmp(o_pc, "stack") == 0)
        return (0);
    if (strcmp(o_pc, "queue") == 0)
        return (1);

    fin_d_fu_mo(o_pc, val_l, nm_l_ine, frt);
    return (frt);
}

/**
 * fin_d_fu_mo - determine the suitable function for the given opcode
 * @cd_op: operation code
 * @vla: cd_op parametere
 * @frt:  storage approach. If 0, nodes follow a stack arrangement.
 * If 1, nodes follow a queue arrangement.
 * @count_ln: line count nm
 * Return: None
 */
void fin_d_fu_mo(char *cd_op, char *vla, int count_ln, int frt)
{
    int itera;
    int glf;

    instruction_t fn_ls[] = {
        {"push", add_to_st_mo},
        {"pall", pri_nt_st_mo},
        {"pint", pri_nt_to_mo},
        {"pop", pop_to_mo},
        {"nop", no_p_mo},
        {"swap", swa_p_no_mo},
        {"add", add_nod_mo},
        {"sub", sub_nod_mo},
        {"div", div_nod_mo},
        {"mul", mul_nodes},
        {"mod", mul_nod_mo},
        {"pchar", print_char},
        {"pstr", pri_nt_ch_mo},
        {"rotl", rot_l_mo},
        {"rotr", rot_r_mo},
        {0, 0}};

    if (cd_op[0] == '#')
        return;

    for (glf = 1, itera = 0; fn_ls[itera].cd_op != 0; itera++)
    {
        if (strcmp(cd_op, fn_ls[itera].cd_op) == 0)
        {
            cal_l_fu_mo(fn_ls[itera].f, cd_op, vla, count_ln, frt);
            glf = 0;
        }
    }
    if (glf == 1)
        err(3, count_ln, cd_op);
}

/**
 * cal_l_fu_mo -  Executes the necessary function.
 * @functi_n:  Pointer indicating the function to be invoked.
 * @cp_op: string denoting the operation code.
 * @vla: string denoting a numerical value.
 * @nl: line number associated with the instruction.
 * @style: Representation style. If 0, nodes adhere to stack structure.
 * If 1, nodes adhere to queue structure.
 */
void cal_l_fu_mo(mn_op_fn functi_n, char *cp_op, char *vla, int nl, int style)
{
    stack_t *nde;
    int gfl;
    int iter;

    gfl = 1;
    if (strcmp(cp_op, "push") == 0)
    {
        if (vla != NULL && vla[0] == '-')
        {
            vla = vla + 1;
            gfl = -1;
        }
        if (vla == NULL)
            er_r_mo(5, nl);
        for (iter = 0; vla[iter] != '\0'; iter++)
        {
            if (isdigit(vla[iter]) == 0)
                er_r_mo(5, nl);
        }
        nde = cre_ate_nod_mo(atoi(vla) * gfl);
        if (style == 0)
            functi_n(&nde, nl);
        if (style == 1)
            add_to_qu_mo(&nde, nl);
    }
    else
        functi_n(&head, nl);
}
