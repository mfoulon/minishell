#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

// Tokens

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_O_PARENT,
	T_C_PARENT,
	T_AND,
	T_OR,
	T_NL,
}	t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

//	Functions

// Expander
char 	**expander_split(char const *s);
void	free_char2(char **tofree);
void	free_char3(char ***tofree);
char	*clean_empty_strs(char *str);
char 	**expander(char *s);
char    *handle_normal_str(char *s, size_t *i);
char    *handle_dollar(char *s, size_t *i);
char    *handle_dquotes(char *s, size_t *i);
char    *handle_squotes(char *s, size_t *i);
static char *handle_dquotes_str(char *s, size_t *i);

#endif
