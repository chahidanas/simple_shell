#include "shell.h"

/*
 * _convtoi - converts a string to an integer
 * @sc: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _convtoi(char *sc)
{
	int i = 0;
	unsigned long int result = 0;

	if (*sc == '+')
	sc++;  /* TODO: why does this make main return 255? */
	for (i = 0;  sc[i] != '\0'; i++)
	{
		if (sc[i] >= '0' && sc[i] <= '9')
		{
			result *= 10;
			result += (sc[i] - '0');
			if (result > INT_MAX)
			return (-1);
		}
		else
		return (-1);
	}
	return (result);
}

/*
 * print_error - prints an error message
 * @info: the parameter and return info struct
 * @strer: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *strer)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(strer);
}

/*
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @filedesc: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int filedesc)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (filedesc == STDERR_FILENO)
	__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
	_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/*
 * convert_number - converter function, a clone of itoa
 * @numb: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int numb, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptnr;
	unsigned long n = numb;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';

	do	{
			*--pntr = array[n % base];
			n /= base;
	} while (n != 0);

	if (sign)
	*--pntr = sign;
	return (pntr);
}
/*
 * remove_comments - function replaces first instance of '#' with '\0'
 * @aos: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *aos)
{
	int i;

	for (i = 0; oas[i] != '\0'; i++)
	if (aos[i] == '#' && (!i || aos[i - 1] == ' '))
	{
		aos[i] = '\0';
		break;
	}
}
