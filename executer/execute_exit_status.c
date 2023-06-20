#include "../include/minishell.h"

int	get_exit_status(int status)
{
	if (wifexited(status))
		return (wexitstatus(status));
	else if (wifsignaled(status))
		return (wtermsig(status));
	return (-1);
}

int	wait_all(pid_t pid)
{
	int	status;
	int	st;

	st = 0;
	waitpid(pid, &status, 0);
	st = status;
	if (wifsignaled(status))
		status = 128 + wtermsig(status);
	else
		status = wexitstatus(status);
	globs.g_exit_status = status;
	if (st == SIGINT || st == SIGQUIT)
	{
		if (st == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDOUT_FILENO);
		else
			ft_putendl_fd("", STDOUT_FILENO);
	}
	while (wait(NULL) != -1)
		;
	return (get_exit_status(status));
}
