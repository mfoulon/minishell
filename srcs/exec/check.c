/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:57 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/19 19:30:43 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_err	ft_check_exec(char *file, bool cmd)
{
	if (!(*file))
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (access(file, X_OK) == -1)
			return ((t_err){ENO_CANT_EXEC, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	if (cmd)
		return ((t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, file});
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}

t_err	ft_check_read(char *file)
{
	if (!(*file))
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) == -1)
			return ((t_err){ENO_GENERAL, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}

t_err	ft_check_write(char *file)
{
	if (!(*file))
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (access(file, W_OK) == -1)
			return ((t_err){ENO_GENERAL, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}