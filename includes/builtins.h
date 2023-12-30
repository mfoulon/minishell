/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:25:12 by mafoulon          #+#    #+#             */
/*   Updated: 2023/12/30 16:47:24 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*  cd_builtin.c */
t_err_no	cd_builtin(char **path);

/*  echo_builtin.c */
t_err_no	echo_builtin(char **args);

/*  env_builtin.c */
t_err_no	env_builtin(void);

/*  exit_builtin.c */
void		exit_builtin(char **args);

/*  export_builtin.c */
char		*extract_key(char *str);
int			check_key(char *str);
t_err_no	export_builtin(char **argv);

/*  pwd_builtin.c */
t_err_no	pwd_builtin(void);
t_bool		check_access(char *path);

/*  pwd_builtin.c */
t_err_no	unset_builtin(char **args);

#endif
