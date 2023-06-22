/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:49 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:50 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	append_elements(t_cmdexe *item, t_cmdlst *ptr)
{
	item->args = get_args(ptr->cmd);
	item->input = open_infiles(ptr->redir);
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
	item->output = open_outfiles(ptr->redir);
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
