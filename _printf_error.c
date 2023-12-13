#include "shell.h"

/**
  *_printf - implementation of own printf that prints without new line
  *@fd: file descriptor to write to
  *@str: string to print
  *
  *Return: Always 0 (Success)
  */
void _printf(int fd, char *str)
{
	size_t len = _strnlen(str);
	char *new_str = malloc(len + 2);

	if (new_str == NULL)
	{
		return;
	}

	_strncpy(new_str, str);
	new_str[len + 1] = '\0';

	write(fd, new_str, len + 1);
	free(new_str);
}
