/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:23:26 by mafoulon          #+#    #+#             */
/*   Updated: 2023/12/20 15:23:28 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "expand.h"
#include "parsing.h"
#include "token.h"

typedef struct s_env
{
    char        *key;
    char        *value;
    struct s_env    *next
}   t_env;

typedef struct s_err
{
    char    *cause;
}   t_err;

typedef struct s_path
{
    t_err   err;
    char        *path;
}   t_path;

typedef struct s_minishell
{
    char        *line;
   // t_token     *tokens;
   // t_token     *curr_token;
    t_node      *ast;
    int             exit_s;
    bool        signint_child;
    t_parse_err parse_err;
    int             stdin;
    int             stdout;
    char        **env;
    t_env       *env_lst;
    bool        hd_sigint;
    struct termios  og_term;
}   t_minishell;

extern  t_minishell     g_minishell;

#endif
