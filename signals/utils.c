/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:40 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:41 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	_wstatus(int status)
{
	int	ex_val;

	ex_val = status & 0177;
	return (ex_val);
}

int	wifsignaled(int status)
{
	int	ex_val;

	ex_val = ((_wstatus(status) != 0177) && (_wstatus(status) != 0));
	return (ex_val);
}

int	wtermsig(int status)
{
	int	ex_val;

	ex_val = _wstatus(status);
	return (ex_val);
}

int	wexitstatus(int status)
{
	int	ex_val;

	ex_val = ((unsigned)status >> 8) & 0xff;
	return (ex_val);
}

int	wifexited(int status)
{
	return (_wstatus(status) == 0);
}
