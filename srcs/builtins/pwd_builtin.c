/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 00:02:29 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/30 16:54:26 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_err_no	pwd_builtin(void)
{
	char	*cwd;
	t_env	*envlst;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (!cwd)
	{
		envlst = g_minishell.env_lst;
		while (strcmp(envlst->key, "PWD"))
			envlst = envlst->next;
		if (!envlst->value)
			return (ENO_GENERAL);
		printf("%s\n", envlst->value);
		return (ENO_SUCCESS);
	}
	ft_garbage_collector(cwd, false);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (ENO_SUCCESS);
}

t_bool	check_access(char *path)
{
	if (access(path, F_OK) == -1)
	{
		write(2, "minishell: cd : ", 16);
		write(2, path, ft_strlen(path));
		write(2, " : no such file or directory\n", 29);
	}
	else if (access(path, X_OK) == -1 && access(path, R_OK) == -1
		&& access(path, W_OK) == -1)
	{
		write(2, "minishell: cd : ", 16);
		write(2, path, ft_strlen(path));
		write(2, " : Permission denied\n", 21);
	}
	else
		return (true);
	return (false);
}
