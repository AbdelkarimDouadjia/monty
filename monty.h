#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
/* Start :Do not edit them */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* End :Do not edit them */

typedef void (*mn_op_fn)(stack_t **, unsigned int);
extern stack_t *head;

/*file operations*/
void fi_lle_op_mo(char *nm_fl);                           /* old: open_file -> new: fi_lle_op_mo / argument= old: file_name -> nm_fl*/ /**/
int par_se_ln_mo(char *bfs, int nm_l_ine, int frt);  /* old: parse_line -> new: par_se_ln_mo*/ /**/
void rea_d_fi_mo(FILE *);                                     /* old: read_file -> new: rea_d_fi_mo*/ /**/
int len_cha_mo(FILE *);                                       /* old: len_chars -> new: len_cha_mo*/
void fin_d_fu_mo(char *, char *, int, int);                   /* old: find_func -> new: fin_d_fu_mo*/

/*Stack operations*/
stack_t *cre_ate_nod_mo(int n);  /* old: create_node -> new: cre_ate_nod_mo*/
void fre_e_nod_mo(void);         /* old: free_nodes -> new: fre_e_nod_mo*/
void pri_nt_st_mo(stack_t **, unsigned int);       /* old: print_stack -> new: pri_nt_st_mo*/
void add_to_st_mo(stack_t **, unsigned int);       /* old: add_to_stack -> new: add_to_st_mo*/
void add_to_qu_mo(stack_t **, unsigned int);       /* old: add_to_queue -> new: add_to_qu_mo*/

void cal_l_fu_mo(mn_op_fn, char *, char *, int, int); /* old: call_fun -> new: cal_l_fu_mo*/

void pri_nt_to_mo(stack_t **, unsigned int);  /* old: print_top -> new: pri_nt_to_mo*/
void pop_to_mo(stack_t **, unsigned int);     /* old: pop_top -> new: pop_to_mo*/
void no_p_mo(stack_t **, unsigned int);       /* old: nop -> new: no_p_mo*/
void swa_p_no_mo(stack_t **, unsigned int);   /* old: swap_nodes -> new: swa_p_no_mo*/

/*Math operations with nodes*/
void add_nod_mo(stack_t **, unsigned int);     /* old: add_nodes -> new: add_nod_mo*/
void sub_nod_mo(stack_t **, unsigned int);     /* old: sub_nodes -> new: sub_nod_mo*/
void div_nod_mo(stack_t **, unsigned int);     /* old: div_nodes -> new: div_nod_mo*/
void mul_nod_mo(stack_t **, unsigned int);     /* old: mul_nodes -> new: mul_nod_mo*/
void mod_nod_mo(stack_t **, unsigned int);     /* old: mod_nodes -> new: mod_nod_mo*/

/*String operations*/
void pri_nt_ch_mo(stack_t **, unsigned int);   /* old: print_char -> new: pri_nt_ch_mo*/
void pri_nt_st_mo(stack_t **, unsigned int);   /* old: print_str -> new: pri_nt_st_mo*/
void rot_l_mo(stack_t **, unsigned int);       /* old: rotl -> new: rot_l_mo*/

/*Error hanlding*/
void er_r_mo(int incorect, ...);     /* old: err -> new: er_r_mo*/
void mor_e_er_mo(int incorect, ...); /* old: more_err -> new: mor_e_er_mo*/
void str_ing_er_mo(int incorect, ...);   /* old: string_err -> new: str_ing_er_mo*/
void rot_r_mo(stack_t **, unsigned int);   /* old: rotr -> new: rot_r_mo*/

#endif
