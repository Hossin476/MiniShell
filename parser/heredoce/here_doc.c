#include "../../include/minishell.h"

int ft_check_g_flag(t_lsttoken *heredoc, t_lstherdoc *item, int *fd)
{
	if (globs.g_flag == 1)
	{
		unlink(heredoc->str);
		const char *ttyname_path = ttyname(1);
		if (ttyname_path)
		{
			int fsd = open(ttyname_path, O_RDWR, 0600);
			if (fsd == -1)
			{
				perror("failed");
				exit(1);
			}
			dup2(0, fsd);
			close(*fd);
			*fd = open(heredoc->str, O_CREAT, 0600);
			item->flag = 1;
		}
		return (1);
	}
	return (0);
}

int ft_fill_heredoc(t_info info, char *lim, int fd)
{
	char *line;
	char *full_line;

	while (1)
	{
		line = readline("here_doc: ");
		if (ft_check_g_flag(info.heredoc, info.item, &fd))
			break;
		if (!line)
		{
			globs.g_exit_status = 0;
			break;
		}
		if (!ft_strcmp_her(line, lim, ft_strlen(line)))
			break;
		full_line = ft_strjoin(line, "\n");
		if (info.heredoc->token == tk_exp || info.heredoc->token == tk_word)
			expand_db_word(&full_line, info.env);
		write(fd, full_line, ft_strlen(full_line));
		free(full_line);
		free(line);
	}
	free(line);
	free(lim);
	return (fd);
}

t_lstherdoc *open_heredoc(t_lsttoken *heredoc, int i, t_env *env)
{
	int fd;
	char *tmp;
	t_lstherdoc *item;

	tmp = generate_name(heredoc, i);
	item = ft_newherdoc(ft_strdup(heredoc->str));
	fd = open(heredoc->str, O_CREAT | O_RDWR, 0644);
	signal(SIGINT, her_sig);
	fd = ft_fill_heredoc((t_info){item, heredoc, env}, tmp, fd);
	close(fd);
	heredoc->token = tk_word;
	globs.g_flag = 0;
	return (item);
}

t_lstherdoc *ft_run_heredoc(t_lsttoken *item, t_env *env, int *flag)
{
	t_lstherdoc *heredoc;
	t_lstherdoc *heredoc_item;
	int i;

	heredoc = NULL;
	i = 0;
	while (item)
	{
		if (item->token == tk_l_her)
		{
			heredoc_item = open_heredoc(item->next, i, env);
			add_heredoc_back(&heredoc, heredoc_item);
			if (heredoc->flag)
				return (*flag = 1, heredoc);
		}
		item = item->next;
		i++;
	}
	return (heredoc);
}

t_lstherdoc *manage_heredocs(t_cmdlst *cmd, t_env *env)
{
	t_lsttoken *item;
	t_cmdlst *cmds;
	t_lstherdoc *heredoc;
	t_lstherdoc *heredoc_item;
	int flag;

	flag = 0;
	heredoc = NULL;
	cmds = cmd;
	while (cmds)
	{
		item = cmds->redir;
		heredoc_item = ft_run_heredoc(item, env, &flag);
		add_heredoc_back(&heredoc, heredoc_item);
		if (flag)
			return (heredoc);
		cmds = cmds->next;
	}
	return (heredoc);
}
