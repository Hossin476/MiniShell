/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:20:36 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:20:37 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	**paths;

	if (!cmd)
		return (NULL);
	path = get_value("PATH", env);
	if (path)
	{
		paths = ft_split(path, ":");
		free(path);
		path = generate_path(paths, cmd);
		return (path);
	}
	return (NULL);
}

int	is_dir(char *path)
{
	struct stat	statbuff;

	stat(path, &statbuff);
	return (S_ISREG(statbuff.st_mode));
}

void	ft_close(t_lstpipe *head)
{
	while (head)
	{
		close(head->fd);
		head = head->next;
	}
}

char	*generate_path(char **paths, char *cmd)
{
	char	*path;
	char	*tmp;
	char	**ptr;

	ptr = paths;
	while (*ptr)
	{
		tmp = ft_strjoin(*ptr, "/");
		if (!ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			free(tmp);
			ft_free(paths);
			return (NULL);
		}
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK | X_OK))
		{
			ft_free(paths);
			return (path);
		}
		free(path);
		ptr++;
	}
	return (ft_free(paths), NULL);
}
