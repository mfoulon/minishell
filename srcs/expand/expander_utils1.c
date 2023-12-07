#include "../../includes/minishell.h"

// frees a **char type of string

void	free_char2(char **tofree)
{
	size_t	i;

	if (!tofree)
		return ;
	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
}

// frees a ***char type of string

void	free_char3(char ***tofree)
{
	size_t	i;

	if (!tofree)
		return ;
	i = 0;
	while (tofree[i])
		free_char2(tofree[i++]);
	free(tofree);
}

// removes the empty strings of type '' and ""

char	*clean_empty_strs(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*res;
	size_t	dstsize;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2])
		|| (str[0] == '"' && str[1] == '"' && !str[2]))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i + 1] == '\'')
			|| (str[i] == '"' && str[i + 1] == '"'))
			i += 2;
		else
			tmp[j++] = str[i++];
	}
	//free(str);
	dstsize = ft_strlen(tmp) + 1;
	res = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(res, tmp, dstsize), free(tmp), res);
}