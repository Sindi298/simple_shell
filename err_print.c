#include "shell.h"

/**
  *err_print - prints to STDERR
  *@s: string to print
  *Return: Always 0 (Success)
  */

void err_print(char *s)
{
	int a = 0;
	char ch;

	if (s)
	{
		ch = s[a];

		while (ch != '\0')
		{
			err_run_printf(STDERR_FILENO, &ch);
			a++;
			ch = s[a];
		}
	}
}
