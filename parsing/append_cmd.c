/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:39 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/28 07:53:39 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	get_io_list(t_io_list **io_list)
{
	t_token_type		redir_type;
	t_io_list			*tmp;

	if (g_minishell.parse_err.type)
		return (false);
	while (g_minishell.curr_token && is_redir(g_minishell.curr_token->type))
	{
		redir_type = g_minishell.curr_token->type;
		get_next_token();
		if (!g_minishell.curr_token
			|| g_minishell.curr_token->type != T_STR)
			return (set_parse_err(E_SYNTAX), false);
		tmp = new_io_node(redir_type, g_minishell.curr_token->value);
		if (!tmp)
			return (set_parse_err(E_MEM), false);
		append_io_node(io_list, tmp);
		get_next_token();
	}
	return (true);
}

t_bool	join_args(char **args)
{
	char	*tmp;

	if (g_minishell.parse_err.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (g_minishell.curr_token
		&& g_minishell.curr_token->type == T_STR)
	{
		// printf("# __DEBUG : ft_strjoin_char(\"%s\", \"%s\", \" \")\n", *args, g_minishell.curr_token->value); // debug
		tmp = *args;
		*args = ft_strjoin_char(*args, g_minishell.curr_token->value, ' ');
		//ft_garbage_collector(args, false);
		// printf("# __DEBUG : after ft_strjoin_char() : args = %s\n", *args);  // debug
		if (!*args)
			return (free(tmp), false);
		free(tmp);
		get_next_token();
	}
	return (true);
}

t_node	*append_cmd(void)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = new_node(N_CMD);
	if (!node)
		return (set_parse_err(E_MEM), NULL);
	while (g_minishell.curr_token
		&& (g_minishell.curr_token->type == T_STR
			|| is_redir(g_minishell.curr_token->type)))
	{
		if (g_minishell.curr_token->type == T_STR)
		{
			if (!join_args(&(node->value)))
				return (clear_cmd_node(node), set_parse_err(E_MEM), NULL);
		}
		else if (is_redir(g_minishell.curr_token->type))
		{
			if (!get_io_list(&(node->io_list)))
				return (free(node->value), free(node), NULL);
		}
	}
	return (node);
}
