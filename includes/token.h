
#ifndef TOKEN_H
# define TOKEN_H

#include "minishell.h"

/*  token_lst.c  */
t_token	*new_token(t_token_type type, char *value);
void add_back_token(t_token *token, t_token **token_list);

/*  token_utils.c  */
t_bool	is_quote(char c);
t_bool	is_space (char c);
t_bool	is_separator(char *str);
void skip_spaces(char **line);
t_bool skip_quotes(char *line, size_t *i);

/*  tokenization_appender.c  */
t_bool handle_separator(char **line, t_token **token_list);
t_bool append_str(char **line, t_token **token_list);
t_bool append_separator(t_token_type type, char **line, t_token **token_list);

/*  tokenize.c  */
t_token		*tokenize(void);

# endif