/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:36:43 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/19 17:06:14 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"


/*	append_cmd.c  */
t_bool	get_io_list(t_io_list **io_list);
t_bool	join_args(char **args);
t_node	*append_cmd(void);

/*	nodes.c  */
t_node	*new_node(t_node_type type);

/*	parse_error.c  */
void	set_parse_err(t_parse_err_type type);
void	handle_parse_err(void);

/*	parse_utils.c  */
t_bool	is_bin_op(t_token *token);
t_bool	is_redir(t_token *token);

/*	parser.c  */
t_node	*parse(void);
t_node	*get_cmd(void);
t_node	*expression(int min_prec);
t_node	*combine(t_token_type operator, t_node *left, t_node *right);

# endif