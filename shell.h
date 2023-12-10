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
int _execute_(char **stores, char **av);

char *_strndup(const char *s);
int _strncmp(char *s1, char *s2);
int _strnlen(char *s);
char *_strncat(char *dest, char *src);
char *_strncpy(char *dest, char *src);

void run_printf(int fd, char *str);
void err_run_printf(int fd, char *str);
void _print(char *s);
void err_print(char *s);

void freearray(char **array);


#endif
