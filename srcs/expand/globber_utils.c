#include "../../includes/minishell.h"
#include <stddef.h>

bool  contains_asterisk(char *s)
{
  size_t  i;

  i = 0;
  while (s[i])
  {
    if (s[i] == '*')
      return (true);
    i++;
  }
  return (false);
}

size_t  ft_arrlen(char **s)
{
  size_t  i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}
