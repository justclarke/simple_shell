#ifndef SHELL_H
#define SHELL_H

/**MACROS**/
#define UNUSED __attribute__((unused)) 
#define BUF_SIZE 1024

/**LIBRARIES**/
#include <stdio.h>
#include <unistd.h>
#include <fctnl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdlib/h>

/**SHELL_FUNCTIONS**/
int shell_interactive(char **av);
int shell_non_interactive(char **av);
#endif
