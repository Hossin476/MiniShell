/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:59 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:00 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_envnew(void)
{
	t_env	*item;

	item = malloc(sizeof(t_env));
	if (!item)
		return (NULL);
	item->key = NULL;
	item->value = NULL;
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

void	add_env_node(t_env **env, char *key, char *value)
{
	t_env	*new_node;

	new_node = ft_envnew();
	new_node->key = ft_strdup(key);
	free(key);
	if (value == NULL)
		new_node->value = NULL;
	else
		new_node->value = ft_strdup(value);
	ft_add_env(env, new_node);
}

t_env	*get_env_node(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_compare(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	free_keys(size_t j, char **ptr)
{
	while (j)
	{
		free(ptr[j - 1]);
		j--;
	}
	free(ptr);
}
