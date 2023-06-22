#include "../../include/minishell.h"

t_cmdexe	*cmdexe_new(void)
{
	t_cmdexe	*item;

	item = malloc(sizeof(t_cmdexe));
	if (!item)
		return (NULL);
	item->input = 0;
	item->output = 1;
	item->args = NULL;
	item->error_log = NULL;
	item->next = NULL;
	return (item);
}

void	addcmdexe_back(t_cmdexe **head, t_cmdexe *new)
{
	t_cmdexe	*item;

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

int	is_built_in(char *str)
{
	if (!ft_strcmp(str, "export") || !ft_strcmp(str, "cd") || !ft_strcmp(str,
			"echo") || !ft_strcmp(str, "env") || !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

size_t	ft_cmd_size(t_lsttoken *cmd)
{
	size_t	i;

	i = 0;
	while (cmd)
	{
		if (cmd->token == tk_wt_s)
			cmd = cmd->next;
		else
		{
			cmd = cmd->next;
			i++;
		}
	}
	return (i);
}

char	**get_args(t_lsttoken *cmds)
{
	char	**args;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_cmd_size(cmds) + 1;
	args = (char **)malloc(sizeof(char *) * len);
	while (i < len - 1)
	{
		if (cmds->token == tk_wt_s)
			cmds = cmds->next;
		else
		{
			args[i] = ft_strdup(cmds->str);
			i++;
			cmds = cmds->next;
		}
	}
	args[i] = NULL;
	return (args);
}
