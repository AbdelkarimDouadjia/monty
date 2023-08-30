#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
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
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

typedef void (*op_func)(stack_t **, unsigned int);
int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file);
void push(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void addnode(stack_t **stack, int n);
void freemem(stack_t *stack);
void queue(stack_t **stack, unsigned int line_no);
void addqueue(stack_t **stack, int n);
void starck(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_no);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);
void divs(stack_t **stack, unsigned int line_no);
#endif
