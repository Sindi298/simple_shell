#include "shell.h"

/**
  **_getpath_ - finds a command in the path string
  *@string: the path string
  *
  *Return: path of command if found or NULL if not found
 */

char *_getmypath_(char *string)
{
	char *my_envpath;
	char *my_fullstring;
	char *my_dir;
	struct stat stat_info;
	int j;

	for (j = 0; string[j]; j++)
	{
		if (string[j] == '/')
		{
			if (stat(string, &stat_info) == 0)
				return (_strndup(string));
			return (NULL);
		}
	}
	my_envpath = _mygetenv("PATH");
	if (!my_envpath)
		return (NULL);
	my_dir = strtok(my_envpath, ":");
	while (my_dir)
	{
		my_fullstring = malloc(_strnlen(my_dir) + _strnlen(string) + 2);
		if (my_fullstring)
		{
			_strncpy(my_fullstring, my_dir);
			_strncat(my_fullstring, "/");
			_strncat(my_fullstring, string);
			if (stat(my_fullstring, &stat_info) == 0)
			{
				free(my_envpath);
				return (my_fullstring);
			}
			free(my_fullstring), my_fullstring = NULL;
			my_dir = strtok(NULL, ":");
		}
	}
	free(my_envpath);
	return (NULL);
}
