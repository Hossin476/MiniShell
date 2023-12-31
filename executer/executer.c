/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:30 by lshail            #+#    #+#             */
/*   Updated: 2023/06/23 22:22:35 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_execute_builtins(t_cmdexe *cmd, char **args, t_env **env)
{
	if (args == NULL || args[0] == NULL)
		return (1);
	if (cmd->error_log)
		return (printf("%s", cmd->error_log), g_globs.g_exit_status = 1, 1);
	dup2(cmd->output, 1);
	if (ft_compare(args[0], "echo") == 0)
		return (ft_echo_command(args, *env));
	else if (ft_compare(args[0], "pwd") == 0)
		return (ft_pwd_command(args, *env));
	else if (ft_compare(args[0], "cd") == 0)
		return (ft_cd_command(args, *env));
	else if (ft_compare(args[0], "unset") == 0)
		ft_unset_command(args, env);
	else if (ft_compare(args[0], "export") == 0)
		return (ft_export_command(args, env));
	else if (ft_compare(args[0], "exit") == 0)
		ft_exit_command(args, *env);
	else if (ft_compare(args[0], "env") == 0)
		ft_env_command(args, *env);
	else
		return (0);
	return (1);
}

char	*check_path(char *args, t_env *env)
{
	char	*path;

	if (!ft_strcmp(args, "."))
		return (ft_putstr_fd("filename argument required\n", 2), exit(2), NULL);
	if (!ft_strcmp(args, ".."))
		return (ft_putstr_fd("Error: command not found\n", 2), exit(127), NULL);
	path = get_path(args, env);
	if (!path || !ft_strcmp(args, ""))
		return (ft_putstr_fd("Error: command not found\n", 2), exit(127), NULL);
	return (path);
}

void	ft_add_fd(t_lstpipe **head, int fd1, int fd2)
{
	ft_lst_add_pipe(head, ft_lstnew_pip(fd1));
	ft_lst_add_pipe(head, ft_lstnew_pip(fd2));
}

void	free_pipe(t_lstpipe *head)
{
	t_lstpipe	*item;

	item = head->next;
	while (item)
	{
		free(head);
		head = item;
		item = item->next;
	}
	free(head);
}
