#include "shell.h"

/**
  *_strncmp - compares 2 strings
  *@s1: string 1
  *@s2: string 2
  *
  *Return: 0 if equal
  */

int _strncmp(char *s1, char *s2)
{
	int b;

	b = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		b = (int)*s1 - (int)*s2;
	}
	return (b);
}

/**
  *_strnlen - string length
  *@s: string to be checked
  *
  *Return: length of string
  */

int _strnlen(char *s)
{
	int c = 0;

	if (!s)
		return (0);

	while (*s++)
		c++;
	return (c);
}

/**
  *_strndup - duplicates a string
  *@s: string to duplicate
  *
  *Return: pointer to the duplicated string
  */
char *_strndup(const char *s)
{
	int length = 0;
	char *result;

	if (s == NULL)
		return (NULL);
	while (*s++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--s;
	return (result);
}

/**
  *_strncat - concatenates two strings
  *@dest: the destination buffer
  *@src: the source buffer
  *
  *Return: pointer to destination buffer
  */

char *_strncat(char *dest, char *src)
{
	char *g = dest;

	while (*g)
		g++;

	while (*src)
	{
		*g = *src;
		g++;
		src++;
	}
	*g = *src;
	return (dest);
}

/**
  *_strncpy - copies string
  *@dest: destination string
  *@src: source string
  *
  *Return: the destination string
  */

char *_strncpy(char *dest, char *src)
{
	int a = 0;

	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
