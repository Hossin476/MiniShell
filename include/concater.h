#ifndef CONCATER_H
# define CONCATER_H

# include "minishell.h"

t_cmdlst	*ft_concater(t_cmdlst *head);
void		ft_free_garbage(t_lsttoken *item, char *str1, char *str2);
int			ft_link_nodes(t_lsttoken *item);
void		concate_cmd(t_lsttoken **head);
void		ft_concate_redir(t_lsttoken **head);

#endif
