#include "shell.h"

/**
  **_getenv - gets the environment variable value
  *@env_var: environment variable
  *
  *Return: environment variable value or null on error
 */

char *_mygetenv(char *env_var)
{
	char *my_temp;
	char *my_key;
	char *env_value;
	char *my_env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		my_temp = _strndup(environ[i]);
		my_key = strtok(my_temp, "=");
		if (_strncmp(my_key, env_var) == 0)
		{
			env_value = strtok(NULL, "\n");
			my_env = _strndup(env_value);
			free(my_temp);
			return (my_env);
		}
		free(my_temp), my_temp = NULL;
	}
	return (NULL);
}
