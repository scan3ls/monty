#ifndef MONTY_H
#define MONTY_H
#define FAILURE -1712

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global Variable */
extern int params[1024];

/* monty.c */
 /* main */
void gracefullExit(char *line, stack_t *list, int lineNum, char *opCode);
void resetCode(char *opCode);

/* line.c */
char *trim(char *line);
int getLength(char *line);
char *getOpCode(char *line);
int getValue(char *line);

/* command.c */
void (*getFunc(char *opCode))(stack_t **stack, unsigned int line_number);
int isValid(char *opCode, char value);
void freeStack(stack_t *stack);

/* 1-opCodes.c */
void pushNode(stack_t **stack, unsigned int line_number);
void printNodes(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 2-opCodes.c */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
