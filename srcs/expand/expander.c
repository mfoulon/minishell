#include "../../includes/minishell.h"

static char  *pre_expander(char *s)
{
    char *res;
    size_t i;

    res = ft_strdup("");
    i = 0;
    while (s[i])
    {
        if (s[i] =='\'')
            res = ft_strjoin_free(res, handle_squotes(s, &i));
        else if (s[i] =='"')
            res = ft_strjoin_free(res, handle_dquotes(s, &i));
        //else if (s[i] =='$')
            //res = ft_strjoin_free(res, handle_dollar(s, &i));
        else
            res = ft_strjoin_free(res, handle_normal_str(s, &i));
    }
    return (res);
}

char **expander(char *s)
{
    char    **expanded;
    char    **res;
    size_t      i;

    s = pre_expander(s);
    if (!s)
        return (NULL);
    s = clean_empty_strs(s);
    if (!s)
        return (NULL);
    expanded = expander_split(s);
    free(str);
    if (!expanded)
        return (NULL);
    res = globber(expanded);
    if (!res)
        return (NULL);
    return (res);
}