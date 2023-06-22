#include "../include/minishell.h"

int	check_option(char *word, char opt_chr)
{
	int	i;

	i = 1;
	if (word[0] != '-' || ft_strlen(word) < 2)
		return (0);
	while (word[i])
	{
		if (word[i] != opt_chr)
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo_command(char **args, t_env *env)
{
	int	i;
	int	bol;

	(void)env;
	bol = 1;
	i = 1;
	while (args[i] && check_option(args[i], 'n'))
	{
		bol = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (!args[i + 1])
			break ;
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (bol == 1)
		write(1, "\n", 1);
	g_globs.g_exit_status = 0;
	return (0);
}
