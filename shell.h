#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
char *_get_path(char **env);
void exit_shell(char **arg, char *lineptr, int _exit);
void print_environment(char **env);
int fork_exec(char **arg, char **av, char **env, char *lineptr, int np, int c);
char *_getline_command(void);
char *_custom_strchr(const char *s, int c);
size_t _custom_strspn(const char *s1, const char *s2);
size_t _custom_strcspn(const char *s1, const char *s2);
char *_custom_strtok(char *str, const char *delim);
#endif