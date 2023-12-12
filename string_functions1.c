#include "shell.h"

/**
  *rev_string - function reverses a string
  *@str: string to be reversed
  *@len: string length to be printed
  *
  *Return: reversed string
  */
void rev_string(char *str, int len)
{
	char ret;
	int begin = 0;
	int finish = len - 1;

	while (begin < finish)
	{
		ret = str[begin];
		str[begin] = str[finish];
		str[finish] = ret;
		begin++;
		finish--;
	}
}

/**
  *_putchar - prints chhar to stdout
  *@ch: char
  *
  *Return: 1 on success, -1 on error
  */
int _putchar(char ch)
{
	static int c;
	static char buf[BUF_SIZE];

	if (ch == BUF_FLUSH || c >= BUF_SIZE)
	{
		write(STDOUT_FILENO, buf, c);
	}

	if (ch != BUF_FLUSH)
		buf[c++] = ch;
	return (1);
}

/**
  *_puts - prints a string
  *@str: string to be printed (char[])
  *
  *Return: void
  */
void _puts(char *str)
{
	int c = 0;

	if (!str)
		return;

	while (str[c] != '\0')
	{
		_putchar(str[c]);
		c++;
	}
}

