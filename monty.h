#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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

typedef void (*mn_op_fn)(stack_t **, unsigned int);
extern stack_t *head;

void mor_e_er_mo(int incorect, ...);
void str_ing_er_mo(int incorect, ...);
void rot_r_mo(stack_t **, unsigned int);
void er_r_mo(int incorect, ...);

void add_nod_mo(stack_t **, unsigned int);
void div_nod_mo(stack_t **, unsigned int);
void sub_nod_mo(stack_t **, unsigned int);
void mod_nod_mo(stack_t **, unsigned int);
void mul_nod_mo(stack_t **, unsigned int);

void pri_nt_st_mo(stack_t **, unsigned int);
stack_t *cre_ate_nod_mo(int n);
void add_to_st_mo(stack_t **, unsigned int);
void add_to_qu_mo(stack_t **, unsigned int);
void fre_e_nod_mo(void);

void cal_l_fu_mo(mn_op_fn, char *, char *, int, int);

void no_p_mo(stack_t **, unsigned int);
void pop_to_mo(stack_t **, unsigned int);
void swa_p_no_mo(stack_t **, unsigned int);
void pri_nt_to_mo(stack_t **, unsigned int);

void rot_l_mo(stack_t **, unsigned int);
void pri_nt_ch_mo(stack_t **, unsigned int);
void pri_nt_st_mo(stack_t **, unsigned int);

int len_cha_mo(FILE *);
int par_se_ln_mo(char *bfs, int nm_l_ine, int frt);
void fin_d_fu_mo(char *, char *, int, int);
void rea_d_fi_mo(FILE *);
void fi_lle_op_mo(char *nm_fl);

#endif
