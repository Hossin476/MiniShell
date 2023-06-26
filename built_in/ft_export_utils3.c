/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:01 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:02 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_export_solo(t_env *env)
{
	char	**keys;
	int		i;
	char	*key;
	char	*value;

	i = 0;
	keys = key_to_array(env);
	sort_array_of_keys(keys);
	while (keys[i])
	{
		key = keys[i];
		value = get_env_value(env, key);
		if (value != NULL)
			printf("declare -x %s=\"%s\"\n", key, value);
		else
			printf("declare -x %s\n", key);
		i++;
	}
	free_keys(i, keys);
}

void	update_env_node(t_env **env, char *key, char *value)
{
	t_env	*node;

	node = get_env_node(*env, key);
	if (node != NULL && value != NULL)
	{
		free(node->value);
		node->value = ft_strdup(value);
		free(key);
	}
	else if (node != NULL && value == NULL)
	{
		node = node->next;
		free(key);
	}
	else
		add_env_node(env, key, value);
	if (value != NULL && (node == NULL || node->value != value))
		free(value);
}

void	initialize_export_vars(char **args, t_env *env, t_export_vars *vars)
{
	vars->bol = 0;
	vars->i = 1;
	if (strlen_double_ptr(args) == 1)
		ft_export_solo(env);
}
