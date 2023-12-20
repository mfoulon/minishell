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

#include "minishell.h"

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
			// free(token_list) + ?
		if (is_space(*line))		// libft?
			skip_spaces(&line);		// fct to do -> utils
		else if (is_separator(line))	// fct to do -> utils
			error_checker = !handle_separator(&line, token_list);
		else
			error_checker = !append_str(&line, token_list);	// fct to do
	}
	return (token_list);
}

// t_bool	buffer_info_cmp(t_buffer_info *b_info, t_buffer_info *to_compare)
// {
// 	if (b_info->io_info->redir_in == to_compare->io_info->redir_in
// 		&& b_info->io_info->redir_out == to_compare->io_info->redir_out
// 		&& b_info->io_info->heredoc_mode == to_compare->io_info->heredoc_mode
// 		&& b_info->io_info->append_mode == to_compare->io_info->append_mode)
// }

// t_bool	is_token_identifier(char c)
// {
// 	if (c == '<'
// 		|| c == '>'
// 		|| c == '|')
// 		return (true);
// 	return (false);
// }

// t_token_type	which_is_next_token(char *buffer, int i)
// {
	
// }

// void	tokenise_in(t_token **token, char *buffer, t_buffer_info b_info, int i)

