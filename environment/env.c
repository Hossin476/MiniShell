#include "../include/minishell.h"

static t_env	*ft_new_env(char *key, char *value)
{
	t_env	*item;

	item = malloc(sizeof(t_env));
	if (!item)
		return (NULL);
	item->key = ft_valdup(key);
	item->value = ft_valdup(value);
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

void	ft_add_env(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

t_env	*env_init(char **env)
{
	t_env_init	env_data;
	char		*key;
	char		*value;
	int			len;
	t_env		*new_env;

	env_data.head = NULL;
	env_data.i = 0;
	while (env[env_data.i])
	{
		len = 0;
		while (env[env_data.i][len] && env[env_data.i][len] != '=')
			len++;
		key = ft_substr(env[env_data.i], 0, len);
		value = ft_strdup(ft_strchr(env[env_data.i], '=') + 1);
		new_env = ft_new_env(key, value);
		if (new_env == NULL)
			return (NULL);
		free(value);
		free(key);
		ft_add_env(&env_data.head, new_env);
		env_data.i++;
	}
	return (env_data.head);
}
