#include "shell.h"

/**
  *main - shell main function
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
	int element = 0;
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
		element++;

		stores = split(storec);
		if (!stores)
			continue;

		if (my_builtin(stores[0]))
			get_my_builtin(stores, av, &my_waitstatus, element);
		else
		my_waitstatus = _execute_(stores, av, element);
	}
	return (0);

}
