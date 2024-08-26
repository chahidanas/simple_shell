#include "shell.h"

/*
 **_memset - fills memory with a constant byte
 *@p: the pointer to the memory area
 *@b: the byte to fill *s with
 *@ab: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *p, char b, unsigned int ab)
{
	unsigned int i;

	for (i = 0; i < ab; i++)
	p[i] = b;
	return (p);
}

/*
 * free - frees a string of strings
 * @sos: string of strings
 */

void free(char **sos)
{
	char **a = sos;

	if (!sos)
	return;
	while (*sos)
	free(*sos++);
	free(a);
}

/*
 * _realloc - reallocates a block of memory
 * @pntr: pointer to previous malloc ated block
 * @o_size: byte size of previous block
 * @n_size: byte size of new block
 *
 * Return: pointer to the ol'block namen.
 */
void *_realloc(void *pntr, unsigned int o_size, unsigned int n_size)
{
	char *p;

	if (!pntr)
	return (malloc(n_size));
	if (!n_size)
	return (free(pntr), NULL);
	if (n_size == o_size)
	return (pntr);

	p = malloc(n_size);
	if (!p)
	return (NULL);

	o_size = o_size < n_size ? o_size : n_size;
	while (o_size--)
	p[o_size] = ((char *)pntr)[o_size];
	free(pntr);
	return (p);
}
