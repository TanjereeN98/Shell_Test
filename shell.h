#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFSIZE 1024
int get_mode(int argc);
char *read_line(void);
void new_process(char **args, char **argv);
char *_strdup(char *str);
char **token_line(char *line);
int _strlen(char *s);
int tokens_count(char *str, char *delim);
char *_strcpy(char *dest, char *src);
#endif
