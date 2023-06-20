#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "minishell.h"

typedef struct s_here_doc
{
	char			*path;
	int				flag;
	struct s_here_doc	*next;
}	t_lstherdoc;

typedef struct s_info
{
	t_lstherdoc *item;
	t_lsttoken *heredoc;
	t_env *env;
}	t_info;

t_lstherdoc *manage_heredocs(t_cmdlst *cmd,t_env *env);
t_lstherdoc * open_heredoc(t_lsttoken * heredoc,int i,t_env *env);
int ft_strcmp_her(char *s1, char *s2, size_t n);
t_lstherdoc *ft_newherdoc(char *path);
void add_heredoc_back(t_lstherdoc **head, t_lstherdoc *new);
char	*generate_name(t_lsttoken *heredoc,int i);
int ft_check_g_flag(t_lsttoken *heredoc,t_lstherdoc *item,int *fd);
int ft_fill_heredoc(t_info info,char *lim,int fd);
t_lstherdoc *ft_run_heredoc(t_lsttoken *item,t_env *env,int *flag);
void her_sig(int sig);

#endif
