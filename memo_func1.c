#include "shell.h"

/*
 * bfr - frees a pointer and NULLs the address
 * @pntr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfr(void **pntr)
{
	if (ptrs && *ptrs)
	{
		free(*pntr);
		*pntr = NULL;
		return (1);
	}
	return (0);
}
