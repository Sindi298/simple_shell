#include "shell.h"

/**
  **convert_int - converter function
  *@num: number to convert
  *
  *Return: pointer to a string
  */

char *convert_int(int num)
{
	char str_buf[20];
	int counter = 0;

	if (num == 0)
		str_buf[counter++] = '0';
	else
	{
		while (num > 0)
		{
			str_buf[counter++] = (num % 10) + '0';
			num /= 10;
		}
	}
	str_buf[counter] = '\0';
	rev_string(str_buf, counter);
	return (_strndup(str_buf));
}
