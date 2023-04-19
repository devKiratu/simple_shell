#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void process_input(char *buffer, char *name, char *envp[]);
char **create_argv(char *s);
void execute_path(char *argv[], char *name, char *envp[]);

#endif
