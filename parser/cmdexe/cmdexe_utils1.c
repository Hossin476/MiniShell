/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexe_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:46 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/24 00:22:43 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	not_file_name(t_lsttoken *item)
{
	if(!item)
		return(1);
	if (item->token == tk_l_dir || item->token == tk_r_dir
		|| item->token == tk_r_her || item->token == tk_l_her
		|| item->token == tk_exp || item->token == tk_joined)
		return (1);
	return (0);
}

int	get_fd(int fd, t_lsttoken *item)
{
	if (fd != 1)
		close(fd);
	if (item->token == tk_r_her)
		fd = open(item->str, O_CREAT | O_APPEND | O_RDWR,
				0644);
	else
		fd = open(item->str, O_CREAT | O_RDWR | O_TRUNC,
				0644);
	return (fd);
}

int	open_infiles(t_lsttoken *item)
{
	int	fd;

	fd = 0;
	if (!item)
		return (-1);
		if (not_file_name(item))
			return (fd = -1);
		else
		{
			if (fd != 0)
				close(fd);
			fd = open(item->str, O_RDWR, 0644);
			if (fd < 0)
				return (-2);
		}
	return (fd);
}

int	open_outfiles(t_lsttoken *item)
{
	int	fd;

	fd = 1;
	if(!item)
		return (-1);
	if (not_file_name(item))
		return (-1);
	else
	{
		fd = get_fd(fd, item);
		if (fd < 0)
			return (-2);
	}
	return (fd);
}

