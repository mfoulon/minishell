#include "minishell.h"

char	*ft_clean_empty_strs(char *str)
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
	free(str);
	dstsize = ft_strlen(tmp) + 1;
	res = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(res, tmp, dstsize), free(tmp), res);
}

// int main() {
//     char input[] = "Hello '' World '\"' Extra '' Quotes";
//     printf("Input String: %s\n", input);

//     char *output = ft_clean_empty_strs(input);
//     printf("Output String: %s\n", output);

//     // Don't forget to free the dynamically allocated memory
//     free(output);

//     return 0;
// }
