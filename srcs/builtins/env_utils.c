#include "../../includes/minishell.h"

char    *get_envlst_val(char *key)
{
    t_env   *env_lst;

    env_lst = g_minishell.env_lst;
    while(env_lst)
    {
        if (!ft_strcmp(key, env_lst->key))
            return (env_lst->value);
        env_lst = env_lst->next;
    }
    return (NULL);
}