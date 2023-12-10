#include "shell.h"

/**
  *_execute_ - executes a command
  *@stores: pointer array of strings
  *@av: pointer array of arguments
  *
  *Return: exit status
  */

int _execute_(char **stores, char **av)
{
	pid_t my_forkRV;
	int my_waitstatus;

	my_forkRV = fork();

	if (my_forkRV == 0)
	{
		if (execve(stores[0], stores, environ) == -1)
		{
			perror(av[0]);
			freearray(stores);
			exit(0);
		}
	}

	else
	{
		waitpid(my_forkRV, &my_waitstatus, 0);
		freearray(stores);
	}

	return (WEXITSTATUS(my_waitstatus));
}
