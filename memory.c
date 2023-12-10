#include "shell.h"

/**
  *freearray - frees a pointer and NULLS the address
  *@array: address of the pointer to free
  *
  *Return: Void
  */

void freearray(char **array)
{
	int k;

	if (!array)
		return;

	for (k = 0; array[k]; k++)
	{
		free(array[k]);
		array[k] = NULL;
	}

	free(array), array = NULL;
}
