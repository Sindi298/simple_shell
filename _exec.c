#include "shell.h"

/**
  *_execute_ - executes a command
  *@stores: pointer array of strings
  *@av: pointer array of arguments
  *@element: index of string input
  *
  *Return: exit status
  */

int _execute_(char **stores, char **av, int element)
{
	char *my_fullstring;
	pid_t my_forkRV;
	int my_waitstatus;

	my_fullstring = _getmypath_(stores[0]);
	if (!my_fullstring)
	{
		_myprinterror(av[0], stores[0], element);
		freearray(stores);
		return (127);
	}

	my_forkRV = fork();
	if (my_forkRV == 0)
	{
		if (execve(my_fullstring, stores, environ) == -1)
		{
			free(my_fullstring), my_fullstring = NULL;
			freearray(stores);
		}
	}

	else
	{
		waitpid(my_forkRV, &my_waitstatus, 0);
		freearray(stores);
		free(my_fullstring), my_fullstring = NULL;
	}

	return (WEXITSTATUS(my_waitstatus));
}
