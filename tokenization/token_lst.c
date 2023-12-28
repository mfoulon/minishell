/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:24:42 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/28 07:52:20 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*get_first_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token && token->prev)
	{
		token = token->prev;
		printf("# __DEBUG : (gft) Token value %s\n", token->value); // debug
	}
	return (token);
}

t_bool	is_space(char c)
{
	if (!c)
		return (false);
	return (c == ' '
		|| c == '\t' || c == '\n'
		|| c == '\r' || c == '\v'
		|| c == '\f');
}

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*new_token;

	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	return (new_token);
}

void	add_back_token(t_token *token, t_token **token_list)
{
	t_token	*curr_token;

	if (!*token_list)
	{
		*token_list = token;
		print_token(token); // debug
		return ;
	}
	curr_token = *token_list;
	while (curr_token && curr_token->next)
		curr_token = curr_token->next;
	curr_token->next = token;
	token->prev = curr_token;
	printf("# __DEBUG : last token added\n"); // debug
	print_token(token); // debug
}

/* DEBUG FUNCTIONS */

void	print_token(t_token *token)
{

	printf("\tTYPE : %s\tVALUE : %s\n", get_token_type(token), token->value);
	if (token->prev)
		printf("\t\tPREV => TYPE : %s\tVALUE : %s\n", get_token_type(token->prev), token->prev->value);
	else
		printf("\t\t NO PREVIOUS TOKEN\n");
	if (token->next)
		printf("\t\tPREV => TYPE : %s\tVALUE : %s\n\n", get_token_type(token->next), token->next->value);
	else
		printf("\t\t NO NEXT TOKEN\n\n");
}
