#include "shell.h"

/**
  *run_printf - Implementation of own printf function that prints string
  *@fd: file descripter to write to
  *@str: string to print
  *
  *Return: Always 0 (Success)
  */

void run_printf(int fd, char *str)
{
	size_t len = _strlen(str);
	char *new_str = malloc(len + 2);

	if (new_str == NULL)
	{
		return;
	}

	_strncpy(new_str, str);
	new_str[len] = '\n';
	new_str[len + 1] = '\0';

	write(fd, new_str, len + 1);
	free(new_str);
}
