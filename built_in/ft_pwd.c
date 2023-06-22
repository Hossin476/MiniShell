#include "../include/minishell.h"

int	ft_pwd_command(char **args, t_env *env)
{
	char	*pwd;

	(void)args;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		ft_putendl_fd(get_env_value(env, "PWD"), 1);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	g_globs.g_exit_status = 0;
	return (0);
}
