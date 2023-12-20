/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:51:57 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/20 16:11:20 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export_builtin(char **argv)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (export_list(), 0);
	while (argv[i])
	{
		if (check_key(argv[i]) == 0)
			exit_s = export_err_msg(argv[i]);
		else
		{
			key = extract_key(argv[i]);
			if (env_entry_exists(key))
				update_envlst(key, extract_value(argv[i]), false);
			else
				update_envlst(key, extract_value(argv[i]), true);
		}
		i++;
	}
	return (exit_s);
}
