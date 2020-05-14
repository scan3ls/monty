#include "monty.h"

int params[1024] = {0};
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
	ssize_t fread;
	char *fileName = argv[1];
	unsigned int lineNum = 0;
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

	while ((fread = getline(&line, &len, fp)) > 0)
	{
		opCode = getOpCode(line);
		value = getValue(line);
		params[lineNum] = value;
		lineNum++;
		func = getFunc(opCode);
		if (func == NULL)
			gracefullExit(line, list, lineNum, opCode);
		func(&list, lineNum);
		free(opCode);
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
