#include "../include/minishell.h"

void ft_run_cmd(t_cmdexe *cmd,char **args, t_env *env)
{
	char *path;
	char **en;

	en = env_to_array(env);
	path = NULL;
	if (!*args)
		exit(0);
	if (is_built_in(*args))
		return (ft_execute_builtins(cmd,args, env), exit(0));
	if (is_path(*args))
	{
		path = ft_strdup(*args);
		if (access(path, F_OK) == -1)
			return (perror(""), exit(127));
		if (access(path, X_OK) == -1)
			return (perror(""), exit(126));
		if(is_dir(path)==0)
			return(perror("is a directory"),exit(126));
	}
	else
		path = check_path(*args,env);
	if (execve(path, args, en) == -1)
		return (ft_putstr_fd("Error: command not found\n", 2), exit(1));
}

int ft_execute(t_cmdexe *cmd,t_fd fd , t_env *env, t_lstpipe *pip)
{
	pid_t pid;

	if (cmd->input != 0)
		fd.input = cmd->input;
	if (cmd->output != 1)
		fd.output = cmd->output;
	pid = fork();
	if (pid == -1)
		return (perror("ERROR !!"), exit(1), -1);
	setup_signals(pid);
	if (pid == 0)
	{
		dup2(fd.input, 0);
		dup2(fd.output, 1);
		ft_close(pip);
		if (cmd->error_log)
		{
			ft_putstr_fd(cmd->error_log, 2);
			exit(1);
		}
		else
			ft_run_cmd(cmd,cmd->args, env);
	}
	return (pid);
}

void execute_multiple_cmd(t_cmdexe *cmd, t_env *env)
{
	t_lstpipe *head;

	head = NULL;
	int fd[2];
	int new_fd[2];
	pipe(fd);
	ft_add_fd(&head,fd[0],fd[1]);
	ft_execute(cmd, (t_fd){STDIN_FILENO, fd[1]}, env, head);
	cmd = cmd->next;
	while (cmd->next && cmd->next)
	{
		pipe(new_fd);
		ft_add_fd(&head,new_fd[0],new_fd[1]);
		close(fd[1]);
		ft_execute(cmd, (t_fd){fd[0], new_fd[1]}, env, head);
		close(fd[0]);
		fd[0] = new_fd[0];
		fd[1] = new_fd[1];
		cmd = cmd->next;
	}
	int id = ft_execute(cmd, (t_fd){fd[0], STDOUT_FILENO}, env, head);
	ft_close(head);
	free_pipe(head);
	wait_all(id);
}

int ft_run_single_cmd(t_cmdexe *cmd, t_env *env)
{
	pid_t pid;

	pid = fork();
	setup_signals(pid);
	if (pid == 0)
	{
		dup2(cmd->input, 0);
		dup2(cmd->output, 1);
		if (cmd->error_log)
		{
			ft_putstr_fd(cmd->error_log, 2);
			close(cmd->input);
			close(cmd->output);
			exit(1);
		}
		else
			ft_run_cmd(cmd,cmd->args, env);
	}
	wait_all(pid);
	return (pid);
}

void ft_execute_cmd(t_cmdexe *cmd, t_env *env)
{
	t_cmdexe *cmdr;
	if (!cmd)
		return;
	cmdr = cmd;
	if (ft_lstsize_cmd(cmdr) == 1 && is_built_in(*(cmdr->args)))
		ft_execute_builtins(cmd, cmdr->args, env);
	else if (ft_lstsize_cmd(cmdr) == 1 && !is_built_in(*(cmdr->args)))
		ft_run_single_cmd(cmdr, env);
	else
		execute_multiple_cmd(cmdr, env);
	handle_signal(0);
}
