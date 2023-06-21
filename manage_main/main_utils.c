#include "../include/minishell.h"

void	ft_clean_node(t_cmdexe *item)
{
	if (item->input != 0)
		if (!close(item->input))
			if (item->output != 1)
				close(item->output);
	free(item->error_log);
	ft_free_args(item->args);
	free(item->args);
	free(item);
}

void	ft_freecdexe(t_cmdexe *head)
{
	t_cmdexe	*item;

	if (!head)
		return ;
	item = head->next;
	while (item)
	{
		ft_clean_node(head);
		head = item;
		item = item->next;
	}
	ft_clean_node(head);
}
void	ft_eof(char *line)
{
	if (line == NULL)
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
}

void	ft_unlink_heredocs(t_lstherdoc *redir)
{
	t_lstherdoc	*tmp;

	tmp = redir;
	if (!redir)
		return ;
	while (tmp)
	{
		unlink(tmp->path);
		tmp = tmp->next;
	}
	tmp = redir->next;
	while (tmp)
	{
		free(redir->path);
		free(redir);
		redir = tmp;
		tmp = tmp->next;
	}
	free(redir->path);
	free(redir);
}

int	ft_check_heredoc(t_lstherdoc *item)
{
	while (item)
	{
		if (item->flag)
			return (1);
		item = item->next;
	}
	return (0);
}

