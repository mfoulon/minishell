#include "../../includes/minishell.h"

static char *handle_dquotes_str(char *s, size_t *i)
{
    size_t  start;

    start = *i;
    while (s[*i] != '"' && s[*i] != '$')
        (*i)++;
    return (ft_substr(s, start, *i - start));
}

char    *handle_squotes(char *s, size_t *i)
{
    size_t  start;

    start = *i;
    (*i)++;
    while (s[*i] != '\'')
        (*i)++;
    (*i)++;
    return (ft_substr(s, start, *i - start));
}

char    *handle_dquotes(char *s, size_t *i)
{
    char    *res;
    res = ft_strdup("\"");
    (*i)++;
    while (res[*i] != '\"')
    {
        //if (s[*i] == '$')
        //    res = ft_strjoin_free(res, handle_dollar(s, i));
        //else
            res = ft_strjoin_free(res, handle_dquotes_str(s, i));
    }
    (*i)++;
    return (ft_strjoin_free(res, ft_strdup("\"")));
}

char    *handle_dollar(char *s, size_t *i)
{
    char    *res;
    return (res);
}

char    *handle_normal_str(char *s, size_t *i)
{
    size_t  start;

    start = *i;
    while (s[*i] && s[*i] != '\'' && s[*i] != '"' && s[*i] != '$')
        (*i)++;
    return (ft_substr(s, start, *i - start));
}
