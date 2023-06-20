#include "../include/minishell.h"

char	*ft_valdup(const char *s1)
{
	int		len;
	char	*d1;

	if (!s1 || !*s1)
		return (NULL);
	len = ft_strlen(s1);
	d1 = (char *)malloc(len + 1);
	if (!d1)
		return (NULL);
	while (*s1)
	{
		*d1 = *s1;
		d1++;
		s1++;
	}
	*d1 = '\0';
	return (d1 - len);
}

int	strlen_double_ptr(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_error_check(char *cmd, char *word, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (word)
		ft_putstr_fd(word, 2);
	if (status == 0)
		ft_putstr_fd(": HOME not set\n", 2);
	else if (status == 1)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (status == 2)
		ft_putstr_fd(": too many arguments\n", 2);
	else if (status == 3)
		ft_putstr_fd(": numeric argument required\n", 2);
	else if (status == 4)
		ft_putstr_fd(": not a valid identifier\n", 2);
	else if (status == 5)
		ft_putstr_fd(": OLDPWD not set\n", 2);
	else if (status == 6)
		ft_putstr_fd(": error retrieving current directory\
		getcwd: cannot access parent directories: No such file or directory\n",
		2);
	globs.g_exit_status = 1;
	return (0);
}

int	ft_compare(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*get_env_value(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_compare(env->key, key) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}
