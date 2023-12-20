/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:23:15 by mafoulon          #+#    #+#             */
/*   Updated: 2023/12/20 15:23:17 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

#include "minishell.h"

// Expander
char 	**expander_split(char const *s);
void	free_char2(char **tofree);
void	free_char3(char ***tofree);
char	*clean_empty_strs(char *str);
bool	is_valid_char(char c);
char 	**expander(char *s);
char    *handle_normal_str(char *s, size_t *i);
char    *handle_dollar(char *s, size_t *i);
char    *handle_dquotes(char *s, size_t *i);
char    *handle_squotes(char *s, size_t *i);
static char *handle_dquotes_str(char *s, size_t *i);
bool	is_star_match(char *pattern, char *s);
bool  contains_asterisk(char *s);
size_t  ft_arrlen(char **s);
size_t  match_count(char *pattern);
char  **join_mult_arrs(char ***s);
char    **globber(char **expanded);
void    expand_heredoc(char *s, int fd);
char    *strip_quotes(char *s);

 #endif