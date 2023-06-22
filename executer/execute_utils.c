/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:20:41 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:20:42 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lstsize_cmd(t_cmdexe *cmd)
{
	int	len;

	len = 0;
	while (cmd)
	{
		cmd = cmd->next;
		len++;
	}
	return (len);
}

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

t_lstpipe	*ft_lstnew_pip(int fd)
{
	t_lstpipe	*item;

	item = malloc(sizeof(t_lstpipe));
	item->fd = fd;
	item->next = NULL;
	return (item);
}

void	ft_lst_add_pipe(t_lstpipe **head, t_lstpipe *new)
{
	t_lstpipe	*item;

	if (!*head)
	{
		*head = new;
		return ;
	}
	item = *head;
	while (item->next)
		item = item->next;
	item->next = new;
}

int	is_path(char *cmd)
{
	char	*path;

	path = ft_strchr(cmd, '/');
	if (path)
		return (1);
	return (0);
}
