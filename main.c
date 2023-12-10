#include "shell.h"

/**
  *main - simple shell main function
  *@ac: the count of arguments
  *@av: the argument vector
  *
  *Return: 0 Always (success)
  */

int main(int ac, char **av)
{
	char *storec = NULL;
	char **stores = NULL;
	int my_waitstatus = 0;
	/*declaring void variables*/
	(void)ac;

	while (1)
	{
		storec = read_string();
		/* reaches EOF ctrl + d */
		if (storec == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (my_waitstatus);
		}
		stores = split(storec);
		if (!stores)
			continue;
		my_waitstatus = _execute_(stores, av);
	}

	return (0);

}
