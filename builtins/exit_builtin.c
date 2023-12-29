/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:08:04 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/29 19:36:20 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_bool	is_str_a_number(char *str);
static int		exittoi(char *s, int sign);
static void		skip_spaces_and_get_sign(char *s, int *i, int *sign);

void	exit_builtin(char **args)
{
	t_err_no	exit_s;

	exit_s = g_minishell.exit_s;
	if (args[1])
	{
		if (args[2] && is_str_a_number(args[1]))
		{
			exit_s = print_and_ret_err(
					(t_err){ENO_GENERAL, ERRMSG_TOO_MANY_ARGS, NULL});
			(clean_minishell(), exit(exit_s));
		}
		else
			exit_s = exittoi(args[1], 1);
	}
	if (g_minishell.hd_sigint)
		exit_s = 130;
	(clean_minishell(), exit(exit_s));
}

static t_bool	is_str_a_number(char *str)
{
	str--;
	while (*(++str))
		if (!ft_isdigit(*str))
			return (false);
	return (true);
}

static void	skip_spaces_and_get_sign(char *s, int *i, int *sign)
{
	while (s[*i] && s[*i] == ' ')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

static int	exittoi(char *s, int sign)
{
	int					i;
	int					exit_s;
	unsigned long long	result;

	i = -1;
	skip_spaces_and_get_sign(s, &i, &sign);
	if (!is_str_a_number(s + i))
	{
		exit_s = print_and_ret_err((t_err){ENO_EXEC_255,
				ERRMSG_NUMERIC_REQUI, s});
		(clean_minishell(), exit(exit_s));
	}
	result = 0;
	while (s[++i])
	{
		result = (result * 10) + (s[i] - '0');
		if (result > LONG_MAX)
		{
			exit_s = print_and_ret_err((t_err){ENO_EXEC_255,
					ERRMSG_NUMERIC_REQUI, s});
			(clean_minishell(), exit(exit_s));
		}
	}
	return ((result * sign) % 256);
}
