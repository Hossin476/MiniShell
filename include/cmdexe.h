/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:23:40 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/25 12:24:31 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDEXE_H
# define CMDEXE_H
# include "minishell.h"

typedef struct s_cmdexe
{
	char			**args;
	char			*error_log;
	int				input;
	int				output;
	struct s_cmdexe	*next;
}	t_cmdexe;

t_cmdexe	*cmdexe_new(void);
void		addcmdexe_back(t_cmdexe **head, t_cmdexe *new);
size_t		ft_cmd_size(t_lsttoken *cmd);
int			is_built_in(char *str);
int			not_file_name(t_lsttoken *item);
char		**get_args(t_lsttoken *cmds);
int			open_infiles(t_lsttoken *item);
int			open_outfiles(t_lsttoken *head);
t_cmdexe	*creat_cmdexe(t_cmdlst *cmds);
int			get_fd(int fd, t_lsttoken *item);
void		ft_check_error_redir(t_cmdexe *item);

#endif
