/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:36:43 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/29 19:26:14 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

/*	append_cmd.c  */
t_bool		get_io_list(t_io_list **io_list);
t_bool		join_args(char **args);
t_node		*append_cmd(void);

/*	nodes.c  */
t_node		*new_node(t_node_type type);
t_io_list	*new_io_node(t_token_type type, char *value);
t_io_type	get_io_type(t_token_type type);
t_node_type	get_node_type(t_token_type type);
void		append_io_node(t_io_list **lst, t_io_list *new);

/*	parse_error.c  */
void		set_parse_err(t_parse_err_type type);
void		handle_parse_err(void);

/*	parse_utils.c  */
t_bool		is_bin_op(void);
t_bool		is_redir(t_token_type type);
void		get_next_token(void);
int			ft_prec(t_token_type type);
int			curr_token_prec(void);

/*	parser.c  */
t_node		*parse(void);
t_node		*get_cmd(void);
t_node		*expression(int min_prec);
t_node		*combine(t_token_type operator, t_node *left, t_node *right);

/* DEBUG */

void		print_node(t_node *node, int margin);
char		*get_node_type_str(t_node *node);
void		print_io_list(t_io_list *list, int margin);
void		print_redirection(t_io_list *redir, int margin);
void		print_ast(t_node *ast, int margin);
char		*get_io_type_str(t_io_list *io);

#endif
