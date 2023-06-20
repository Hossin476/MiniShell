#include "../include/minishell.h"

int	ft_setenv(t_env **head, char *key, char *value)
{
	char	*tmp;
	t_env	*current;

	if (key == NULL)
		return (-1);
	current = *head;
	while (current != NULL)
	{
		if (ft_compare(current->key, key) == 0)
		{
			tmp = current->value;
			current->value = ft_valdup(value);
			free(tmp);
			tmp = NULL;
			return (0);
		}
		current = current->next;
	}
	return (0);
}

void	update_env_value(t_env *env, char *key, char *value)
{
	while (env != NULL)
	{
		if (get_env_value(env, key) == NULL)
		{
			env->value = ft_valdup(value);
			return ;
		}
		if (ft_compare(env->key, key) == 0 && get_env_value(env, key) != NULL)
		{
			free(env->value);
			env->value = ft_valdup(value);
			return ;
		}
		env = env->next;
	}
}

char	*get_cd_path(char **args, t_env *env)
{
	char	*path;
	char	*oldpwd;

	path = NULL;
	if (!args[1] || ft_compare(args[1], "~") == 0)
	{
		path = get_env_value(env, "HOME");
		if (!path && ft_error_check("cd", 0, 0))
			return (NULL);
	}
	else if (ft_compare(args[1], "-") != 0)
	{
		path = args[1];
	}
	else if (ft_compare(args[1], "-") == 0)
	{
		oldpwd = get_env_value(env, "OLDPWD");
		if (!oldpwd && ft_error_check("cd", 0, 5))
			return (NULL);
		if (oldpwd != NULL)
			printf("%s\n", oldpwd);
		path = oldpwd;
	}
	return (path);
}

int	change_directory(char *path, char *old_pwd, t_env *env)
{
	char	*new_pwd;

	if (path && path[0] && chdir(path) == -1)
	{
		ft_error_check("cd", path, 1);
		free(old_pwd);
		return (1);
	}
	new_pwd = getcwd(0, 0);
	if (!new_pwd)
	{
		ft_error_check("cd", path, 6);
		return (1);
	}
	ft_setenv(&env, "OLDPWD", old_pwd);
	ft_setenv(&env, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	globs.g_exit_status = 0;
	return (0);
}

int	ft_cd_command(char **args, t_env *env)
{
	char	*path;
	char	*old_pwd;
	int		ret;

	path = get_cd_path(args, env);
	if (!path)
		return (1);
	old_pwd = getcwd(0, 0);
	ret = change_directory(path, old_pwd, env);
	return (ret);
}
