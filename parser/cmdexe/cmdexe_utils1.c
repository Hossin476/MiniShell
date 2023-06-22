#include "../../include/minishell.h"

int	not_file_name(t_lsttoken *item)
{
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
		fd = open(item->next->str, O_CREAT | O_APPEND | O_RDWR,
				0644);
	else
		fd = open(item->next->str, O_CREAT | O_RDWR | O_TRUNC,
				0644);
	return (fd);
}

int	open_infiles(t_lsttoken *item)
{
	int	fd;

	fd = 0;
	if (!item)
		return (0);
	while (item)
	{
		if ((item->token & (tk_l_dir | tk_l_her)) && item->next)
		{
			if (not_file_name(item->next))
				return (fd = -1);
			else
			{
				if (fd != 0)
					close(fd);
				fd = open(item->next->str, O_RDWR, 0644);
				if (fd < 0)
					return (-2);
			}
		}
		else if (item->token == tk_l_dir && !item->next)
			fd = -1;
		item = item->next;
	}
	return (fd);
}

int	ft_open_outfile(t_lsttoken *item)
{
	int	fd;

	fd = 1;
	while (item)
	{
		if ((item->token & (tk_r_dir | tk_r_her)) && item->next)
		{
			if (not_file_name(item->next))
				return (-1);
			else
			{
				fd = get_fd(fd, item);
				if (fd < 0)
					return (-2);
			}
		}
		else if ((item->token & (tk_r_dir | tk_r_her)) && !item->next)
			fd = -1;
		item = item->next;
	}
	return (fd);
}

int	open_outfiles(t_lsttoken *head)
{
	int	fd;

	fd = 1;
	if (!head)
		return (fd);
	return (ft_open_outfile(head));
}
