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
	t_env	*head;
	int		i;
	char	*key;
	char	*value;
	int		len;
	t_env	*new_env;

	head = NULL;
	i = 0;
	while (env[i])
	{
		len = 0;
		while (env[i][len] && env[i][len] != '=')
			len++;
		key = ft_substr(env[i], 0, len);
		value = ft_strdup(ft_strchr(env[i], '=') + 1);
		new_env = ft_new_env(key, value);
		if (new_env == NULL)
			return (NULL);
		free(value);
		free(key);
		ft_add_env(&head, new_env);
		i++;
	}
	return (head);
}
