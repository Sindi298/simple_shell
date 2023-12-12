#include "shell.h"

/**
  *read_string - reads string from stdin & prints prompt to stdout
  *Return: pointer string array
  */

char *read_string(void)
{
	char *storec = NULL;
	size_t size = 0;
	ssize_t my_getRV;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	my_getRV = getline(&storec, &size, stdin);
	if (my_getRV == -1)
	{
		free(storec), free(NULL);
		return (NULL);
	}
	return (storec);
}
