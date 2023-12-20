/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:16:15 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/18 11:06:18 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static t_token	create_token_list(char *line);

t_token		*tokenize(void)
{
	t_token			*token_list;
	char			*line;

	line = g_minishell.line;
	token_list = create_token_list(line);
	free(line);
	g_minishell.line = NULL;
	return (token_list);	
}

static t_token	create_token_list(char *line)
{
	t_bool		error_checker;
	t_token		*token_list;

	error_checker = false;
	token_list = NULL;
	while (*line)
	{
		if (error_checker)
			return(clear_token_lst(&token_list), NULL); // faire clean_token_lst
		if (is_space(*line))
			skip_spaces(&line);
		else if (is_separator(line))
			error_checker = !handle_separator(&line, token_list);
		else
			error_checker = !append_str(&line, token_list);
	}
	return (token_list);
}
