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

typedef enum	e_node_type{
	N_CMD,
	N_PIPE,
	N_AND,
	N_OR
}	t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND
}	t_io_type;

typedef enum e_parse_err_type
{
	E_MEM = 1,
	E_SYNTAX
}	t_parse_err_type;

typedef struct s_io_list
{
	t_io_type			type;
	char				*value;
	char				**exp_value;
	int					fd_heredoc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}	t_io_list;

typedef struct	s_node
{
	t_node_type		type;
	t_io_list		*io_list;
	char			*value;
	char			**exp_value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;


# endif