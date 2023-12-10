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
	write(fd, str, strlen(str));
}
