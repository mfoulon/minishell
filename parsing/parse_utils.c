/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:04:01 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/28 07:53:09 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	is_bin_op(void)
{
	t_token_type	type;

	if (!g_minishell.curr_token)
		return (false);
	type = g_minishell.curr_token->type;
	if (type == T_PIPE || type == T_AND || type == T_OR)
		return (true);
	return (false);
}

t_bool	is_redir(t_token_type type)
{
	if (!type)
		return (false);
	return (type == T_REDIR_IN
		|| type == T_REDIR_OUT
		|| type == T_APPEND_OUT
		|| type == T_HEREDOC_IN);
}

void	get_next_token(void)
{
	g_minishell.curr_token = g_minishell.curr_token -> next;
}

int	ft_prec(t_token_type type)
{
	if (type == T_OR || type == T_AND)
		return (0);
	return (1);
}

int	curr_token_prec(void)
{
	return (ft_prec(g_minishell.curr_token->type));
}

/* DEBUGING FUNCTIONS */

void	print_node(t_node *node, int margin)
{
	int	i;

	i = -1;
	while (++i < margin)
		printf("\t");
	printf("\tTYPE = %s\tVALUE = %s\n", get_node_type_str(node), node->value);
	if (node->type == N_CMD)
		print_io_list(node->io_list, i);
}

char	*get_node_type_str(t_node *node)
{
		if (node->type == N_CMD)
		return ("N_CMD");
	else if (node->type == N_PIPE)
		return ("N_PIPE");
	else if (node->type == N_AND)
		return ("N_AND");
	else
		return ("N_OR");
}

char	*get_io_type_str(t_io_list *io)
{
		if (io->type == IO_IN)
		return ("IO_IN");
	else if (io->type == IO_OUT)
		return ("IO_OUT");
	else if (io->type == IO_APPEND)
		return ("IO_APPEND");
	else
		return ("IO_HEREDOC");
}

void	print_io_list(t_io_list *list, int margin)
{
	if (!list)
		return;
	while (list->next)
	{
		print_redirection(list, margin);
		list = list->next;
	}
	print_redirection(list, margin);
}

void	print_redirection(t_io_list *redir, int margin)
{
	int	i;

	i = -1;
	while (++i < margin)
		printf("\t");
	if (!redir)
	{
		printf("no redirection");
		return;
	}
	printf("TYPE = %s\tVALUE = %s\n", get_io_type_str(redir), redir->value);
}

void	print_ast(t_node *ast, int margin)
{
	if (!ast)
		printf("AST IS EMPTY\n");
	print_node(ast, margin);
	if (ast->right)
		print_ast(ast->right, margin + 1);
	if (ast->left)
		print_ast(ast->left, margin);
}
