/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:04:01 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/14 15:08:35 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	is_binoperand(t_token token)
{
	if (!token)
		return (false);
	return (token->token_type == T_PIPE
			|| token->token_type == T_AND
			|| token->token_type == T_OR)
}

