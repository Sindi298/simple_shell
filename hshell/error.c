#include "shell.h"

/**
  *_printerror - prints an error message
  *@title: error string to be printed
  *@string: error string to be printed
  *@element: number
  *
  *Return: void
  */
void _printerror(char *title, char *string, int element)
{
	char *head, note[] = ": not found\n";

	head = convert_int(element);

	_printf(STDERR_FILENO, title);
	_printf(STDERR_FILENO, ": ");
	_printf(STDERR_FILENO, head);
	_printf(STDERR_FILENO, ": ");
	_printf(STDERR_FILENO, string);
	_printf(STDERR_FILENO, note);

	free(head);
}

/**
  *_errputs - prints input string
  *@str: string to be printed
  *
  *Return: void
  */
void _errputs(char *str)
{
	int a = 0;

	if (!str)
		return;

	while (str[a] != '\0')
	{
		_errputchar(str[a]);
		a++;
	}
}

/**
  *_errputchar - writes char ch to stderr
  *@ch: char to print
  *
  *Return: on success 1, on error -1
  */
int _errputchar(char ch)
{
	static int a;
	static char buf[BUF_SIZE];

	if (ch == BUF_FLUSH || a >= BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		buf[a++] = ch;
	return (1);
}

/**
  *_putfd - writes char ch to file descriptor
  *@ch: char to print
  *@fd: file descriptor to write to
  *
  *Return: on success 1, on error -1
  */
int _putfd(char ch, int fd)
{
	static int a;
	static char buf[BUF_SIZE];

	if (ch == BUF_FLUSH || a >= BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		buf[a++] = ch;
	return (1);
}

/**
  *_putsfd - prints an input string
  *@str: string to be printed
  *@fd: file descriptor to write to
  *
  *Return: number of char put
  */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);

	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
