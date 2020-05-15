#include "monty.h"

int params[5 * 1024] = {0};
/**
 * main - start of the program
 *@argc: argument count
 *@argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *opCode;
	size_t len = 0;
	char *fileName = argv[1];
	unsigned int lineNum;
	int value;
	void (*func)(stack_t **, unsigned int);
	stack_t *list = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

        for (lineNum = 1; getline(&line, &len, fp) > 0; lineNum++)
	{
		opCode = getOpCode(line);
		if (strcmp(opCode, "") == 0)
			continue;
		value = getValue(line);
		params[lineNum] = value;
		func = getFunc(opCode);
		if (func == NULL)
			gracefullExit(line, list, lineNum, opCode);
		func(&list, lineNum);
		resetCode(opCode);
	}
	free(line);
	fclose(fp);
	freeStack(list);
	return (0);
}

/**
 * gracefullExit - exit if no commands are found
 *@line: command line checked
 *@list: current stack
 *@lineNum: current command line number
 *@opCode: pointer to command string
 */
void gracefullExit(char *line, stack_t *list, int lineNum, char *opCode)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
		lineNum, opCode);
	free(line);
	freeStack(list);
	exit(EXIT_FAILURE);
}

/**
 * resetCode - reset char pointer
 *@opCode: poitner to reset
 */

void resetCode(char *opCode)
{
	int i;

	free(opCode);
	for (i = 0; i < 10; i++)
	{
		opCode[i] = 0;
	}
}
