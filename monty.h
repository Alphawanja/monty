#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
extern int num;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked lists node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instructions_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO,FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pushS(stack_t **s_stack, unsigned int lin);
void printS(stack_t **s_stack, unsigned int lin);
void pintS(stack_t **s_stack, unsigned int lin);
void popS(stack_t **s_stack, unsigned int lin);
void swapS(stack_t **s_stack, unsigned int lin);
void adds(stack_t **s_stack, unsigned int lin);
void nopS(stack_t **s_stack, unsigned int lin);
void subS(stack_t **s_stack, unsigned int lin);
void divS(stack_t **s_stack, unsigned int lin);
void mulS(stack_t **s_stack, unsigned int lin);
void modS(stack_t **s_stack, unsigned int lin);
void comS(stack_t **s_stack, unsigned int lin);
void pcharS(stack_t **s_stack, unsigned int lin);

void inter_monty(char **av);
void token_line(char **buffer, char ***tokens, ssize_t r_line);
void opcode_choose(stack_t **s_stack, char ***tokens, unsigned int lin);
void freetokens(char ***tokens);
void freest_stack(stack_t *s_stack);
void deletenl(char **buffer);
void tokenizer(char **buffer, char ***tokens);
void checknumber(char *n, unsigned int line_number);
void (*choose_opcode(char *code))(stack_t **s_stack, unsigned int lin);

#endif
