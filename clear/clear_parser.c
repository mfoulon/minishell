/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:56 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/20 17:51:25 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear.h"

void	clear_io_list(t_io_list **lst)
{
	t_io_list	*curr_node;
	t_io_list	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		ft_free_char2(curr_node->expanded_value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

void	clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	clear_io_list(&(node->io_list));
	free(node->args);
	ft_free_char2(node->expanded_args);
}

void	recursive_clear_ast(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_CMD)
		clear_cmd_node(node);
	else
	{
		if (node->left)
			recursive_clear_ast(node->left);
		if (node->right)
			recursive_clear_ast(node->right);
	}
	free(node);
}

void	clear_ast(t_node **ast)
{
	recursive_clear_ast(*ast);
	*ast = NULL;
	clear_token_list(&g_minishell.tokens);
}