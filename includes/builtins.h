#ifndef BUILTINS_H
# define BUILTINS_H

#include "minishell.h"

/*  env_builtin.c */
t_err_no  env_builtin(void);

/*  export_builtin.c */
int	export_builtin(char **argv);

 #endif