#include "shell.h"

/*
 * interact - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/*
 * does_delime - checks if character is a delimeter
 * @c: the char to check
 * @delime: the delimeter string
 * Return: 1 if true, 0 if false
 */
int does_delime(char c, char *delime)
{
	while (*delime)
	if (*delime++ == c)
	return (1);
	return (0);
}

/*
 *_doesalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _doesalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);
	else
	return (0);
}

/**
 *_stoi - converts a string to an integer
 *@stoc: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _stoi(char *stoc)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; stoc[i] != '\0' && flag != 2; i++)
	{
		if (stoc[i] == '-')
		sign *= -1;

		if (stoc[i] >= '0' && stoc[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (stoc[i] - '0');
		}
		else if (flag == 1)
		flag = 2;
	}

	if (sign == -1)
	output = -result;
	else
	output = result;

	return (output);
}
