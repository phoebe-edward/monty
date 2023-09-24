#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
/**
 * struct args_s - structure of arguments
 * @argv: string containing file path/name
 * @argc: count of num of args
 * @line_num: the line num
 */
typedef struct args_s
{
	char *argv;
	int argc;
	unsigned int line_num;
} args_t;
/**
 * struct data_s - data structure
 * @file_ptr: file pointer
 * @line: pointer to line string
 * @word1: first word of line
 * @stack: stack to be created with opcode (pushed and poped)
 */
typedef struct data_s
{
	FILE *file_ptr;
	char *line;
	char *word1;
	stack_t *stack;
} data_t;
extern data_t *data;
void helping(args_t *args);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void (*func_choice(void))(stack_t **, unsigned int);
void free_all(int all);
void free_stack(void);
int is_int(char *str);
#endif
