#include "monty.h"

/**
 * trim - preps a line to be checked for opcodes, monty commands
 *@line: line to check
 *
 * Return: pointer to  the trimmed line
 */

char *trim(char *line)
{
	int len, i, c;
	char *new_line;

	len = getLength(line);
	new_line = malloc(len);

	for (i = 0, c = 0; i < len; i++)
	{
		if (line[i] == ' ')
			;
		else
		{
			new_line[c] = line[i];
			c++;
		}
	}
	return (new_line);
}

/**
 * getLength - get the length of a string
 *@line - string used
 *
 * Return: length of line as integer
 */

int getLength(char *line)
{
	int i;

	if (line == NULL)
		return (0);
	for (i = 0; line[i] != '\0'; i++)
		;
	return (++i);
}

/**
 * getOpCode - gets opCode from a trimmed line
 *@line: string with opCode
 *
 * Return: opCode
 */

char *getOpCode(char *line)
{
	int len = getLength(line);
	int i, c, flag = 0;
	char *code = malloc(len);

	for (i = 0, c = 0; i < len; i++)
	{
		if (line[i] < 'a' ||  line[i] > 'z')
		{
			if (flag == 1)
				break;
		}
		else
		{
			code[c] = line[i];
			c++;
			flag = 1;
		}
	}
	return (code);
}

/**
 * getValue - gets the value for opcode from a line
 *@line: given line
 *
 * Return: int value in line or -1 if no argument is present
 */

int getValue(char *line)
{
	int len = getLength(line);
	int value, i, c, flag = 0;
	char nums[10];
	nums[0] = 'a';
	for (i = 0, c = 0;i < len; i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			nums[c] = line[i];
			c++;
			flag = 1;
		}
		else
		{
			if (flag == 1)
				break;
		}
	}
	if (nums[0] == 'a')
		return (-1712);

	value = atoi(nums);
	return (value);
}
