#include "shell.h"

/**
  *err_run_printf - print to STDERR
  *@fd: file descriptor to write to
  *@str: string to print
  *Return: Always 0 (Success)
  */

void err_run_printf(int fd, char *str)
{
	write(fd, str, strlen(str));
}
