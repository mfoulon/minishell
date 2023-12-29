/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:46:31 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/29 19:30:21 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_envlst(void)
{
	int		i;
	char	**environ;
	char	*key;
	char	*value;

	environ = g_minishell.env;
	if (!environ)
		return ;
	i = -1;
	while (environ[++i])
	{
		key = extract_key(environ[i]);
		value = extract_value(environ[i]);
		update_envlst(key, value, true);
	}
}

char	*extract_envlst_key(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (ft_garbage_collector(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_garbage_collector(ft_strdup(str), false));
}

char	*extract_value(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (ft_garbage_collector(
					ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

char	*extract_key(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (ft_garbage_collector(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

void	modify_shlvl(char **env, t_bool increase)
{
	int		shlvl;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("SHLVL", env[i], 5))
		{
			if (increase)
				shlvl = ft_atoi(extract_value(env[i])) + 1;
			else
				shlvl = ft_atoi(extract_value(env[i])) - 1;
			env[i] = ft_garbage_collector(ft_strjoin("SHLVL=",
						ft_garbage_collector((ft_itoa(shlvl)),
							false)), false);
		}
		i++;
	}
}
