#ifndef CMDLIST_H
# define CMDLIST_H

# include "minishell.h"

typedef struct s_cmd
{
	t_lsttoken		*cmd;
	t_lsttoken		*redir;
	struct s_cmd	*next;
}	t_cmdlst;

t_cmdlst	*new_cmd(void);
void		lst_add_cmd_back(t_cmdlst *cmd, t_cmdlst **headcmd);
void		ft_lstadd_cmd(t_lsttoken **lst, t_lsttoken *new, t_lsttoken **head);
int			is_redir(t_lsttoken *item);
int			is_cmd(t_lsttoken *item);
int			is_redir_word(t_lsttoken *item);
void		ft_check_cmds(t_cmdlst *headcmd);
void		ft_handle_cmds(t_cmdlst **cmd, t_lsttoken **head);
t_cmdlst	*get_cmdlist(t_lsttoken **head);
t_cmdlst	*get_cmdlist(t_lsttoken **head);

#endif