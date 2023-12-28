/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:08 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/28 07:53:00 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*parse(void)
{
	t_node	*ast;

	g_minishell.curr_token = g_minishell.tokens;
	printf("# __DEBUG : start parsing\n"); // debug
	ast = expression(0);
	printf("# __DEBUG : expression function ended\n"); // debug
	if (g_minishell.curr_token)
		return (set_parse_err(E_SYNTAX), ast);
	printf("# __DEBUG : PRINTING AST . . .\n"); // debug
	print_ast(ast, 0); // debug
	printf("# __DEBUG : parsing ended\n"); // debug
	return (ast);
}

t_node	*get_cmd(void)
{
	if (g_minishell.parse_err.type)
		return (NULL);
	if (is_bin_op())
		return (set_parse_err(E_SYNTAX), NULL);
	return (append_cmd());
}

t_node	*expression(int min_prec)
{
	t_node			*left;
	t_node			*right;
	int				n_prec;
	t_token_type	operator;

	printf("# __DEBUG : start expression function\n"); // debug
	if (g_minishell.parse_err.type || !g_minishell.curr_token)
		return (NULL);
	left = get_cmd();
	if (!left)
		return (NULL);
	while (is_bin_op() && curr_token_prec() >= min_prec)
	{
		operator = g_minishell.curr_token->type;
		get_next_token();
		if (!g_minishell.curr_token)
			return (set_parse_err(E_SYNTAX), left);
		n_prec = ft_prec(operator) + 1;
		right = expression(n_prec);
		if (!right)
			return (left);
		left = combine(operator, left, right);
		if (!left)
			return (clear_ast(&left), clear_ast(&right), NULL);
	}
	return (left);
}

t_node	*combine(t_token_type operator, t_node *left, t_node *right)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = new_node(get_node_type(operator));
	if (!node)
		return (set_parse_err(E_MEM), NULL);
	node->left = left;
	node->right = right;
	return (node);
}
