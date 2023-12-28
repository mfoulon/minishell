/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:16:15 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/28 07:51:42 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	clear_token_lst(t_token **lst)
{
	t_token	*curr_node;
	t_token	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

t_token	*tokenize(void)
{
	t_token			*token_list;
	char			*line;

	printf("# __DEBUG : start tokenization\n"); // debug
	line = g_minishell.line;
	token_list = token_handler(line);
	free(line);
	g_minishell.line = NULL;
	printf("# __DEBUG : tokenization ended\n"); // debug
	printf("# __DEBUG : result of tokenization\n"); // debug
	print_token_list(token_list); // debug
	return (get_first_token(token_list));
}

t_token	*token_handler(char *line)
{
	t_bool		error_checker;
	t_token		*token_list;

	error_checker = false;
	token_list = NULL;
	while (*line)
	{
		if (error_checker)
			return (clear_token_lst(&token_list), NULL);
		if (is_space(*line))
			skip_spaces(&line);
		else if (is_separator(line))
			error_checker = !handle_separator(&line, &token_list);
		else
			error_checker = !append_str(&line, &token_list);
	}
	return (token_list);
}
