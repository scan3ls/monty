#include "monty.h"

int params[1024] = {0};
/**
 * main - start of the program
 *
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	char *opCode, *trimmed;
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
	if (fp < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	while((	fread = getline(&line, &len, fp)) > 0)
	{
		opCode = getOpCode(line);
		value = getValue(line);
		params[lineNum] = value;
		lineNum++;
		if ((func = getFunc(opCode)) == NULL)
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				lineNum, opCode);
			free(trimmed);
			free(line);
			exit(EXIT_FAILURE);
		}
		func(&list, lineNum);
		free(trimmed);
	}
	free(line);
	fclose(fp);
/*	free(list); */
	return (0);
}
