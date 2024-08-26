#include "shell.h"

/*
* _strlength - returns the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/
int _strlength(char *s)
{
	int i = 0;

	if (!s)
	return (0);

	while (*s++)
		i++;
	return (i);
}

/*
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @a1: the first strang
 * @a2: the second strang
 *
 * Return: negative if a1 < a2, positive if a1 > a2, zero if a1 == a2
 */
int _strcmp(char *a1, char *a2)
{
	while (*a1 && *a2)
	{
		if (*a1 != *a2)
		return (*a1 - *a2);
		a1++;
		a2++;
	}
	if (*a1 == *a2)
	return (0);
	else
	return (*a1 < *a2 ? -1 : 1);
}

/*
 * starts_with - checks if needle starts with main_str
 * @main_str: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of main_str or NULL
 */
char *starts_with(const char *main_str, const char *needle)
{
	while (*needle)
	if (*needle++ != *main_str++)
	return (NULL);
	return ((char *)main_str);
}

/*
 * _strcat - concatenates two strings
 * @dests: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dests, char *src)
{
	char *ret = dests;

	while (*dests)
	dests++;
	while (*src)
	*dests++ = *src++;
	*dests = *src;
	return (ret);
}

