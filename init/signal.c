/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:21:55 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/29 19:32:10 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	handle_sigint(int n);

void	init_signals(void)
{
	struct termios	term;

	term = g_minishell.og_term;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_minishell.hd_sigint = false;
	g_minishell.signint_child = false;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_sigint(int n)
{
	(void)n;
	if (g_minishell.signint_child)
	{
		ft_putstr_fd("\n", 1);
		g_minishell.signint_child = false;
		g_minishell.hd_sigint = true;
		g_minishell.exit_s = 130;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_sigquit(int n)
{
	(void)n;
	ft_putstr_fd("Quit: 3\n", 1);
}

void	close_fds(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}
