/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:13:58 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/20 16:57:47 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_ast(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_PIPE
		|| node->type == N_AND
		|| node->type == N_OR)
	{
		init_ast(node->left);
		if (!g_minishell.heredoc_sigint)
			init_ast(node->right);
	}
	else
		init_leaf(node);
}

static void	init_leaf(t_node *node)
{
	t_io_list	*io;
	int			fd[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			g_minishell.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				handle_heredoc(io, fd); // to do
			if (leave_leaf(fd, &pid)) // to do
				return ;
			io->here_doc = fd[0];
		}
		else
			io->expanded_value = expand(io->value);
		io = io->next;
	}
}

static t_bool	leave_leaf(int fd[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	g_minishell.signint_child = false;
	close(fd[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

void	handle_heredoc(t_io_list *io, int fd[2])
{
	char	*line;
	char	*quotes;

	signal(SIGINT, heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (is_delimiter(io->value, line))
			break ;
		if (!*quotes)
			expand_heredoc(line, fd[1]);
		else
		{
			ft_putstr_fd(line, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
	}
	clean_minishell();
	exit(0);
}

static t_bool	is_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!(*delimiter));
}