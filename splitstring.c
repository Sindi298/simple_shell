#include "shell.h"

/**
  ***split - splits a string into words
  *@storec: string
  *
  *Return: pointer to array of words
  */
char **split(char *storec)
{
	char *token = NULL;
	char *temp = NULL;
	char **stores = NULL;
	int i = 0, k = 0;

	if (!storec)
		return (NULL);
	temp = _strndup(storec);
	token = strtok(temp, DELIM);
	if (token == NULL)
	{
		free(storec), storec = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;
	stores = malloc(sizeof(char *) * (i + 1));
	if (!stores)
	{
		free(storec), storec = NULL;
		return (NULL);
	}
	token = strtok(storec, DELIM);
	while (token)
	{
		stores[k] = _strndup(token);
		token = strtok(NULL, DELIM);
		k++;
	}
	free(storec), storec = NULL;
	stores[k] = NULL;
	return (stores);
	freearray(stores);
	free(stores), stores = NULL;
}
