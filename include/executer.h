/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:23:54 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:23:55 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

typedef struct s_lstpipe
{
	int					fd;
	struct s_lstpipe	*next;
}	t_lstpipe;

typedef struct s_fd
{
	int	input;
	int	output;
}	t_fd;

int			ft_execute_builtins(t_cmdexe *cmd, char **args, t_env **env);
void		ft_freecdexe(t_cmdexe *head);
void		ft_execute_cmd(t_cmdexe *cmd, t_env **env);
int			ft_execute(t_cmdexe *cmd, t_fd fd, t_env *env, t_lstpipe *pip);
int			wifsignaled(int status);
int			wtermsig(int status);
int			wexitstatus(int status);
int			wifexited(int status);
int			ft_lstsize_cmd(t_cmdexe *cmd);
void		ft_free(char **path);
t_lstpipe	*ft_lstnew_pip(int fd);
void		ft_lst_add_pipe(t_lstpipe **head, t_lstpipe *new);
int			is_path(char *cmd);
int			get_exit_status(int status);
int			wait_all(pid_t pid);
void		ft_close(t_lstpipe *head);
void		ft_run_cmd(t_cmdexe *cmd, char **args, t_env *env);
void		execute_multiple_cmd(t_cmdexe *cmd, t_env *env);
int			ft_run_single_cmd(t_cmdexe *cmd, t_env *env);
char		*check_path(char *args, t_env *env);
void		ft_add_fd(t_lstpipe **head, int fd1, int fd2);
void		free_pipe(t_lstpipe *head);
char		*get_path(char *cmd, t_env *env);
int			is_dir(char *path);
char		*generate_path(char **paths, char *cmd);

#endif
