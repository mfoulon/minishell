#include "libft.h"

char	*ft_strjoin_char(char *s1, char *s2, char c)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
		return (ft_strjoin(s1, s2));
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	joined = ft_calloc(total_length, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = c;
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (joined);
}

char	*ft_strjoin_char_free(char *s1, char *s2, char c)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
		return (ft_strjoin(s1, s2));
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	joined = ft_calloc(total_length, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = c;
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (free(s1), free(s2), joined);
}

char	**ft_strjoin_char2(char *s1, char *s2, char c)
{
	char	**joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined = ft_calloc(1, sizeof(char *));
	if (!*joined)
		return (NULL);
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
	{
		*joined = ft_strjoin(s1, s2);
		return (joined);
	}	
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	*joined = ft_calloc(total_length, sizeof(char));
	if (!*joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		*joined[i] = s1[i];
		i++;
	}
	*joined[i++] = c;
	j = 0;
	while (s2[j])
		*joined[i++] = s2[j++];
	*joined[i] = 0;
	return (joined);
}