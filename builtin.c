#include "shell.h"

/**
  *my_builtin - compares input string to string in array
  *@string: input string to check and compare
  *
  *Return:on success 0
  */
int my_builtin(char *string)
{
	char *functions[] = {"exit", "env", NULL};

	int a;

	for (a = 0; functions[a]; a++)
	{
		if (_strncmp(string, functions[a]) == 0)
			return (1);
	}
	return (0);
}

/**
  *get_my_builtin - checks for exit and env command
  *@av: not in use, ignore
  *@element: not in use, ignore
  *@stores: string to print
  *@my_waitstatus: argument for called functions
  *Return: nothing
  */
void get_my_builtin(char **stores, char **av, int *my_waitstatus, int element)
{
	(void) av;
	(void) element;

	if (_strncmp(stores[0], "exit") == 0)
		_exitshell(stores, my_waitstatus);

	else if (_strncmp(stores[0], "env") == 0)
		_printenv(stores, my_waitstatus);
}

/**
  *_exitshell - exits the shell
  *@stores: string to be freed on exit
  *@my_waitstatus: exit status
  *
  *Return: nothing
  */
void _exitshell(char **stores, int *my_waitstatus)
{
	freearray(stores);
	exit(*my_waitstatus);
}

/**
  *_printenv - prints environment variables to stdout
  *@stores: input string printed
  *@my_waitstatus: not used, ignore
  *
  *Return: nothing
  */
void _printenv(char **stores, int *my_waitstatus)
{
	int a;

	for (a = 0; environ[a]; a++)
	{
		run_printf(STDOUT_FILENO, environ[a]);
	}
	freearray(stores);
	(*my_waitstatus) = 0;
}
