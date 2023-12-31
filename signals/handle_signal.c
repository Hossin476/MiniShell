/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:37 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:38 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_new_prompt(int signum)
{
	if (signum == SIGINT)
	{
		g_globs.g_exit_status = 1;
		rl_replace_line("", 1);
		ft_putendl_fd("", 1);
		if (rl_on_new_line() == -1)
			exit(0);
		rl_redisplay();
	}
}

void	handle_signal(int sig)
{
	(void)sig;
	rl_catch_signals = 0;
	signal(SIGINT, ft_new_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_children(int signo)
{
	if (signo == SIGQUIT)
	{
		ft_putendl_fd("Quit: 3", 1);
	}
	if (signo == SIGINT)
	{
		ft_putendl_fd("", 2);
	}
	exit(127 + signo);
}

void	setup_signals(pid_t pid)
{
	if (pid == 0)
	{
		signal(SIGQUIT, ft_children);
		signal(SIGINT, ft_children);
	}
	else
		signal(SIGINT, SIG_IGN);
}
