/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:20:40 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/12 12:47:55 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_bool	is_quote(char c)
{
	if (!c)
		return (false);
	return (c == '\'' || c == '\"');
}

t_bool	is_separator(char *str)
{
	if (!str)
		return (false);
	return (is_space(*str)
		|| *str == '<' || *str == '>'
		|| *str == '|' || *str == '\0'
		|| ((*(str + 1) && !ft_strncmp(str, "&&", 2))));
}

void	skip_spaces(char **line)
{
	while (**line && is_space(**line))
		(*line)++;
}

t_bool	skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + (*i) + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		return (true);
	}
	return (print_quote_err(quote), false);
}

void	print_quote_err(char c)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	g_minishell.exit_s = 258;
}


/* DEBUGING FUNCTIONS */

char	*get_token_type(t_token *token)
{
	if (token->type == T_STR)
		return ("T_STR");
	else if (token->type == T_PIPE)
		return ("T_PIPE");
	else if (token->type == T_AND)
		return ("T_AND");
	else if (token->type == T_OR)
		return ("T_OR");
	else if (token->type == T_REDIR_IN)
		return ("T_REDIR_IN");
	else if (token->type == T_REDIR_OUT)
		return ("T_REDIR_OUT");
	else if (token->type == T_APPEND_OUT)
		return ("T_APPEND_OUT");
	else if (token->type == T_HEREDOC_IN)
		return ("T_HEREDOC_IN");
	else
		return ("T_NL");
}

void	print_token_list(t_token *token_list)
{
	if (!token_list)
	{
		printf("token_list is empty\n");
		return;
	}
	while (token_list && token_list->next)
	{
		printf("\tTYPE : %s\tVALUE : %s\n", get_token_type(token_list), token_list->value);
		*token_list = *token_list->next;
	}
	printf("\tTYPE : %s\tVALUE : %s\n", get_token_type(token_list), token_list->value);
}