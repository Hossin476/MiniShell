#include "../include/minishell.h"

char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	**PATHS;

	if (!cmd)
		return (NULL);
	path = get_value("PATH", env);
	if (path)
	{
		PATHS = ft_split(path, ":");
		free(path);
		path = generate_path(PATHS, cmd);
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
char	*generate_path(char **PATHS, char *cmd)
{
	char	*path;
	char	*tmp;
	char	**ptr;

	ptr = PATHS;
	while (*ptr)
	{
		tmp = ft_strjoin(*ptr, "/");
		if (!ft_strncmp(cmd, "", ft_strlen(cmd)))
		{
			free(tmp);
			ft_free(PATHS);
			return (NULL);
		}
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK | X_OK))
		{
			ft_free(PATHS);
			return (path);
		}
		free(path);
		ptr++;
	}
	return (ft_free(PATHS), NULL);
}
