/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:11 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:18:12 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_space(t_lsttoken *item, t_env *env)
{
	char	*value;
	int		i;

	i = 0;
	if (item->token == tk_exp)
	{
		value = get_value(item->str + 1, env);
		if (!value)
			return (value = item->str, 1);
		while (value[i])
		{
			if (value[i] == ' ')
			{
				free(value);
				value = item->str;
				item->str = ft_strjoin("$", value);
				free(value);
				return (0);
			}
			i++;
		}
		free(value);
	}
	return (1);
}

int	is_expandable(t_lsttoken **head, t_lsttoken *item, int mode, t_env *env)
{
	t_lsttoken	*prev;

	prev = NULL;
	if (mode == 0)
	{
		if ((item->token == tk_db_qt || item->token == tk_exp))
			return (1);
	}
	else
	{
		prev = get_prev(head, item);
		if (prev->token != tk_l_her && (item->token == tk_db_qt
				|| (ft_check_space(item, env) && item->token == tk_exp)))
			return (1);
	}
	return (0);
}

t_lsttoken	*get_prev(t_lsttoken **head, t_lsttoken *itm)
{
	t_lsttoken	*item;

	if (!*head || !head)
		return (NULL);
	item = *head;
	while (item && item->next && item->next != itm)
	{
		item = item->next;
	}
	return (item);
}

void	ft_rm_nodes(t_lsttoken **head)
{
	t_lsttoken	*item;
	t_lsttoken	*prev;

	item = *head;
	while (item)
	{
		if ((item->token == tk_wt_s && item->next
				&& item->next->token == tk_wt_s) || (item->token == tk_wt_s
				&& !item->next))
		{
			prev = get_prev(head, item);
			prev->next = item->next;
			free(item->str);
			free(item);
			item = *head;
		}
		item = item->next;
	}
}
