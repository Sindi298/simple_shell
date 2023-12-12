#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>

/* for read/write buffers*/
#define BUF_SIZE 1024
#define BUF_FLUSH -1

#define DELIM " \t\n"
extern char **environ;

char *read_string(void);
char **split(char *storec);
int _execute_(char **stores, char **av, int element);
char *_getpath_(char *string);
char *_getenv(char *env_var);



char *_strndup(const char *s);
int _strncmp(char *s1, char *s2);
int _strnlen(char *s);
char *_strncat(char *dest, char *src);
char *_strncpy(char *dest, char *src);
void rev_string(char *str, int len);

void run_printf(int fd, char *str);
int _putchar(char ch);
void _puts(char *str);
int _putsfd(char *str, int fd);

void _printerror(char *title, char *string, int element);
void _errputs(char *str);
int _errputchar(char ch);
int _putfd(char ch, int fd);

char *convert_int(int num);


void freearray(char **array);


#endif
