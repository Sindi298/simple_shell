#include "shell.h"

/**
  *_print - own printf function
  *@s: string to print
  *Return: Always 0 (Success)
  */

void _print(char *s)
{
	int a = 0;
	char ch;

	if (s)
	{
		ch = s[a];

		while (ch != '\0')
		{
			run_printf(STDOUT_FILENO, &ch);
			a++;
			ch = s[a];
		}
	}
}
