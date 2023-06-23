/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:49 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/24 00:42:07 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_check_error_redir(t_cmdexe *item)
{
	if (item->input == -2)
	{
		free(item->error_log);
		item->error_log = ft_strdup("no such file or directory\n");
	}
	else if (item->input == -1)
	{
		free(item->error_log);
		item->error_log = ft_strdup("ambiguous redirect\n");
	}
	if (item->output == -2)
	{
		free(item->error_log);
		item->error_log = ft_strdup("error opening file\n");
	}
	else if (item->output == -1)
	{
		free(item->error_log);
		item->error_log = ft_strdup("ambiguous redirect\n");
	}
}

static void	append_elements(t_cmdexe *item, t_cmdlst *ptr)
{
	t_lsttoken *redir;
	
	redir = ptr->redir;

	item->args = get_args(ptr->cmd);
	while (redir)
	{
		if ((redir->token & (tk_l_dir | tk_l_her)) )
			item->input = open_infiles(redir->next);
		if(item->input < 0)
			break;
		if ((redir->token & (tk_r_dir | tk_r_her)))
			item->output = open_outfiles(redir->next);
		if(item->output < 0)
			break;
		redir = redir->next;
	}
	ft_check_error_redir(item);
}

t_cmdexe	*creat_cmdexe(t_cmdlst *cmds)
{
	t_cmdexe	*head;
	t_cmdexe	*item;
	t_cmdlst	*ptr;

	head = NULL;
	ptr = cmds;
	while (ptr)
	{
		item = cmdexe_new();
		append_elements(item, ptr);
		addcmdexe_back(&head, item);
		ptr = ptr->next;
	}
	return (head);
}
