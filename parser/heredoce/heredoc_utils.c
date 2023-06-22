#include "../../include/minishell.h"

int	ft_strcmp_her(char *s1, char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	else
		return (ft_strncmp(s1, s2, n));
}

t_lstherdoc	*ft_newherdoc(char *path)
{
	t_lstherdoc	*heredoc;

	heredoc = malloc(sizeof(t_lstherdoc));
	heredoc->path = path;
	heredoc->flag = 0;
	heredoc->next = NULL;
	return (heredoc);
}

void	add_heredoc_back(t_lstherdoc **head, t_lstherdoc *new)
{
	t_lstherdoc	*item;

	if (!*head)
	{
		*head = new;
		return ;
	}
	item = *head;
	while (item->next)
		item = item->next;
	item->next = new;
}

void	her_sig(int sig)
{
	if (sig == SIGINT)
	{
		g_globs.g_flag = 1;
		g_globs.g_exit_status = 1;
		close(0);
	}
}

char	*generate_name(t_lsttoken *heredoc, int i)
{
	char	*path;
	char	*indx;
	char	*tmp;

	indx = ft_itoa(i);
	tmp = heredoc->str;
	heredoc->str = ft_strjoin(tmp, indx);
	free(indx);
	path = ft_strjoin("/var/tmp/", heredoc->str);
	free(heredoc->str);
	heredoc->str = path;
	return (tmp);
}
