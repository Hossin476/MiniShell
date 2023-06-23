/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:15 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:15 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_args(char *env_name)
{
	int	full_length;
	int	env_length;

	full_length = ft_strlen(env_name);
	env_length = ft_check_chars(env_name);
	if (full_length == env_length)
		return (1);
	else
		return (0);
}

t_env	*get_first_node(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->prev)
		env = env->prev;
	return (env);
}

void	ft_clearnode(t_env **env, char *key)
{
	t_env	*node;

	if(!env || !*env)
		return;
	node = *env;
	while (node && ft_compare(node->key, key))
		node = node->next;
	if (!node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if(node == *env)
		*env = (*env)->next;
	free(node->value);
	free(node->key);
	free(node);
	node = NULL;
}

int	ft_unset_command(char **args, t_env **env)
{
	int		flag;
	int		i;
	char	*key;

	flag = 1;
	i = 1;
	while (args[i])
	{
		if (!ft_check_args(args[i]))
		{
			flag = ft_error_check("unset", args[i], 4);
			i++;
			continue ;
		}
		else
		{
			key = args[i];
			ft_clearnode(env, key);
			i++;
		}
	}
	if (flag)
		g_globs.g_exit_status = 0;
	return (flag);
}
