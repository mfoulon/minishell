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

#include "../../includes/minishell.h"

t_bool	is_quote(char c)
{
	if (!c)
		return (false);
	return (c == '\'' || c == '\"')
}

t_bool	is_space (char c)
{
	if (!c)
		return (false);
	retrun (c == ' '
			|| c == '\t' || c == '\n'
			|| c == '\r' || c == '\v'
			|| c == '\f');
}

t_bool	is_separator(char *str)
{
	if (!c)
		return (false);
	return (is_space(*str)
			|| *str == '<' || *str == '>'
			|| *str == '|' || *str == '\0'
			ft_strncmp(str, "&&", 2));
}

void skip_spaces(char **line)
{`
	while (**line && is_space(**line))
		(*line)++;
}

t_bool skip_quotes(char *line, size_t *i)
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
	return (print_quote_err(quote), false); // print_err to do
}