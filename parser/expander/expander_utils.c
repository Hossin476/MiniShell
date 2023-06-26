/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:02 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:18:03 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_expand_cmd(t_lsttoken *item, t_env *env, t_lsttoken **head)
{
	while (item)
	{
		if (!ft_strcmp(item->str, "$?"))
		{
			free(item->str);
			item->str = ft_itoa(g_globs.g_exit_status);
			item->token = tk_word;
			item = item->next;
		}
		else if (is_expandable(head, item, 0, env))
		{
			expand(head, item, env);
			item = *head;
		}
		else
			item = item->next;
	}
}

void	expand_word(t_lsttoken **head, t_lsttoken *item, t_env *env)
{
	char		*value;
	char		**vars;
	t_lsttoken	*prev;
	t_lsttoken	*nodes;
	t_lsttoken	*next;

	next = item->next;
	value = get_value(item->str + 1, env);
	vars = ft_split(value, " \t\r\v\f");
	nodes = creat_list(vars);
	free(vars);
	if (!ft_handle_head(item, head, &nodes, value))
	{
		prev = get_prev(head, item);
		prev->next = nodes;
		prev = get_prev(&nodes, NULL);
		prev->next = next;
		if (ft_strchr(" \t\r\v\f", *value))
			nodes->token = tk_joined;
		free(value);
		free(item->str);
		free(item);
	}
}

char	*get_value(char *var, t_env *env)
{
	size_t	var_len;

	var_len = ft_strlen(var);
	while (env)
	{
		if (var_len == ft_strlen(env->key))
		{
			if (ft_strncmp(var, env->key, var_len) == 0)
				return (ft_strdup(env->value));
		}
		env = env->next;
	}
	return (NULL);
}

int	ft_handle_head(t_lsttoken *item, t_lsttoken **head, t_lsttoken **nodes,
		char *value)
{
	t_lsttoken	*prev;
	t_lsttoken	*next;

	next = item->next;
	if (item == *head)
	{
		if (!*nodes)
			return (*head = next, free(item->str), free(item), 1);
		prev = get_prev(nodes, NULL);
		prev->next = next;
		free(item->str);
		free(item);
		*head = *nodes;
		if (ft_strchr(" \t\r\v\f", *value))
			(*nodes)->token = tk_joined;
		return (free(value), 1);
	}
	if (!*nodes)
	{
		prev = get_prev(head, item);
		prev->next = next;
		return (free(item->str), free(item), 1);
	}
	return (0);
}

t_lsttoken	*creat_list(char **str)
{
	t_lsttoken	*head;
	t_lsttoken	*item;

	if (!str || !*str)
		return (NULL);
	head = NULL;
	while (*str)
	{
		item = ft_lst_new();
		item->str = *str;
		item->token = tk_word;
		ft_lstaddback(&head, item);
		str++;
		if (*str)
		{
			item = ft_lst_new();
			item->str = ft_strdup(" ");
			item->token = tk_wt_s;
			ft_lstaddback(&head, item);
		}
	}
	return (head);
}
