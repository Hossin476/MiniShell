/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:15 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:18:15 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expand(t_lsttoken **head, t_lsttoken *item, t_env *env)
{
	if (item->token == tk_exp)
		expand_word(head, item, env);
	else if (item->token == tk_db_qt || item->token == tk_exp)
		item->token = expand_db_word(&item->str, env);
}

void	ft_expand_redir(t_lsttoken *item, t_env *env, t_lsttoken **head)
{
	while (item)
	{
		if (item->token == tk_l_her)
		{
			item = item->next;
			while (item
				&& !(item->token & (tk_l_dir | tk_r_dir | tk_l_her | tk_r_her)))
				item = item->next;
		}
		if (item && is_expandable(head, item, 1, env))
		{
			expand(head, item, env);
			item = *head;
		}
		else if (item)
			item = item->next;
	}
}

t_cmdlst	*expander(t_cmdlst *head, t_env *env)
{
	t_cmdlst	*cmdlist;
	t_lsttoken	*item;

	cmdlist = head;
	while (cmdlist)
	{
		item = cmdlist->cmd;
		ft_expand_cmd(item, env, &cmdlist->cmd);
		rm_wts_nodes(&cmdlist->cmd);
		item = cmdlist->redir;
		ft_expand_redir(item, env, &cmdlist->redir);
		cmdlist = cmdlist->next;
	}
	return (head);
}
