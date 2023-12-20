/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_appender.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:46:06 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/12 12:45:59 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool handle_separator(char **line, t_token **token_list)
{
	
	if (!ft_strncmp(*line, "<<", 2))
		return (append_separator(T_APPEND_OUT, line, token_list));
	else if (!ft_strncmp(*line, ">>", 2))
		return (append_separator(T_HEREDOC_IN, line, token_list));
	else if (!ft_strncmp(*line, "<", 1))
		return (append_separator(T_REDIR_IN, line, token_list));
	else if (!ft_strncmp(*line, ">", 1))
		return (append_separator(T_REDIR_OUT, line, token_list));
	else if (!ft_strncmp(*line, "&&", 2))
		return (append_separator(T_AND, line, token_list));
	else if (!ft_strncmp(*line, "||", 2))
		return (append_separator(T_OR, line, token_list));
	else
		return (append_separator(T_PIPE, line, token_list));
}

t_bool append_str(char **line, t_token **token_list)
{
	t_token	*token;
	char	*value;
	size_t	i;

	if (!(*line))
		return (false);
	i = 0;
	while ((*line)[i] && !is_separator((*line)[i]))
	{
		if (is_quote((*line)[i]) && !skip_quotes(*line, &i))
			return (false);
		else
			i++;
	}
	value = ft_substr(*line, 0, i);
	if (!value)
		return (false);
	token = new_token(value, T_STR);
	if (!token)
		return (free(value), false);
	*line += i;
	return (add_back_token(token, token_list), true);
}

t_bool append_separator(t_token_type type, char **line, t_token **token_list)
{
	t_token	*token;

	token = new_token(type, value);
	if (!token)
		return (false);
	add_back_token(token, token_list);
	(*line)++;
	if (type == T_APPEND_OUT
		|| type == T_HEREDOC_IN
		|| type == T_AND
		|| type == T_OR)
		(*line)++;
	return (true);
}

// static t_bool			is_inside_quotes(t_buffer_info *b_info);
// static t_buffer_info	check_io_modifier(char c1, char c2, t_buffer_info b_info);

// t_buffer_info	*fill_buffer_info(char *buffer, t_buffer_info *b_info)
// {
// 	size_t	i;
// 	size_t	len;

// 	if (!buffer)
// 		return (0); // valeur de retour d'erreur a verifier
// 	b_info = create_b_info(NULL);
// 	len = strlen(buffer);
// 	i = -1;
// 	while (b_info && ++i < len)
// 	{
// 		if (buffer[i] == '\'' && !(b_info->doub_q_nb % 2))
// 			b_info->simp_q_nb++;
// 		if (buffer[i] == '\"' && !(b_info->simp_q_nb % 2))
// 			b_info->doub_q_nb++;
// 		if (buffer[i] == '|' && !is_inside_quotes(b_info))
// 			b_info = next_b_info(b_info);
// 		if (!is_inside_quotes(b_info) && (buffer[i] == '<' || buffer[i] == '>'))
// 		{
// 			*b_info = check_io_modifier(buffer[i], buffer[i + 1], b_info);
// 			if (buffer[i] == buffer[i + 1])
// 				i++;
// 		}	
// 	}
// 	return (lst_first(b_info));
// }

// static t_bool	is_inside_quotes(t_buffer_info *b_info)
// {
// 	return ((b_info->simp_q_nb % 2 || b_info->doub_q_nb % 2));
// }

// static t_buffer_info	check_io_modifier(char c1, char c2, t_buffer_info b_info)
// {
// 	if (c1 == '<')
// 	{
// 		if (c1 == c2)
// 			b_info->io_info->heredoc_mode++;
// 		else
// 			b_info->io_info->redir_in++;
// 	}
// 	if (c1 == '>')
// 	{
// 		if (c1 == c2)
// 			b_info->io_info->append_mode++;
// 		else
// 			b_info->io_info->redir_out++;
// 	}
// 	return (b_info);
// }

// static b_info	*next_b_info(t_buffer_info *b_info)
// {
// 	if (!b_info || b_info->next)
// 		return (NULL);
// 	b_info->next = create_b_info(b_info);
// 	if (!b_info->next)
// 		return (NULL);
// 	return (b_info->next);
// }