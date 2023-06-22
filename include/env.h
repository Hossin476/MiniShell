#ifndef ENV_H
# define ENV_H

# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *str, int c);
t_env				*env_init(char **env);
char				*ft_strdup(const char *s1);

#endif
