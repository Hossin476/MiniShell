/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:19:11 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:19:12 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	clear_lst(t_lsttoken *head)
{
	t_lsttoken	*lst;

	if (!head)
		return ;
	lst = head->next;
	while (lst)
	{
		free(head->str);
		free(head);
		head = lst;
		lst = lst->next;
	}
	free(head->str);
	free(head);
}

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
}

void	clear_list(t_cmdlst *head)
{
	t_cmdlst	*lst;

	if (!head)
		return ;
	lst = head->next;
	while (lst)
	{
		clear_lst(head->cmd);
		clear_lst(head->redir);
		free(head);
		head = lst;
		lst = lst->next;
	}
	clear_lst(head->cmd);
	clear_lst(head->redir);
	free(head);
}


int	ft_pars(char *line, t_env *ENV, t_cmdexe **finalcmd, t_lstherdoc **item)
{
	t_lsttoken	*head;
	t_cmdlst	*cmdhead;

	head = NULL;
	head = ft_tokenize(line);
	cmdhead = get_cmdlist(&head);
	cmdhead = expander(cmdhead, ENV);
	cmdhead = ft_concater(cmdhead);
	*item = manage_heredocs(cmdhead, ENV);
	if (ft_check_heredoc(*item))
	{
		clear_list(cmdhead);
		ft_unlink_heredocs(*item);
		handle_signal(0);
		*item = NULL;
		return (0);
	}
	*finalcmd = creat_cmdexe(cmdhead);
	clear_list(cmdhead);
	return (1);
}
