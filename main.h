#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void process_input(char **argv, char *name, char *envp[]);
int handle_special_commands(char **argv, char *name);
char **create_argv(char *s);
void execute_path(char *argv[], char *name, char *envp[]);
char *create_full_path(char *cmd, char ***argv);
int _setenv(char *argv[], char *name);
int handle_env_update(char *key, char *new_var, char *name);
int _unsetenv(char *argv[], char *name);
void free_argv(char **argv);

#endif
