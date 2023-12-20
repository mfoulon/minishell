/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:04:01 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/18 17:20:12 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_bin_op(t_token *token)
{
	if (!token)
		return (false);
	return (token->token_type == T_PIPE
			|| token->token_type == T_AND
			|| token->token_type == T_OR)
}

t_bool	is_redir(t_token *token)
{
	if (!token)
		return (false);
	return (token->token_type == T_REDIR_IN
			|| token->token_type == T_REDIR_OUT
			|| token->token_type == T_APPEND_OUT
			|| token->token_type == T_HEREDOC_IN)
}

