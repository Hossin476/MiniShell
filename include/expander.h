#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

t_cmdlst	*expander(t_cmdlst *head, t_env *env);
void		ft_expand_redir(t_lsttoken *item, t_env *env, t_lsttoken **head);
void		ft_expand_cmd(t_lsttoken *item, t_env *env, t_lsttoken **head);
void		expand(t_lsttoken **head, t_lsttoken *item, t_env *env);
int			expand_db_word(char **str, t_env *env);
char		*expand_dbq(t_lsttoken *ptr, t_env *env);
int			ft_check_word(t_lsttoken *ptr, char **word);
void		rm_wts_nodes(t_lsttoken **head);
void		ft_rm_nodes(t_lsttoken **head);
void		expand_word(t_lsttoken **head, t_lsttoken *item, t_env *env);
int			ft_handle_head(t_lsttoken *item, t_lsttoken **head,
				t_lsttoken **nodes, char *value);
t_lsttoken	*get_prev(t_lsttoken **head, t_lsttoken *itm);
t_lsttoken	*creat_list(char **str);
char		*get_value(char *var, t_env *env);
int			is_expandable(t_lsttoken **head, t_lsttoken *item,
				int mode, t_env *env);
int			ft_check_space(t_lsttoken *item, t_env *env);
int			ft_str_exp(char *str);
int			ft_white_space(char **str, char **line);
int			word_len(char *str);
int			get_word(char **str, char **line);
t_lsttoken	*tokinze_db_word(char *line);
void		ft_free_token(t_lsttoken *head);

#endif