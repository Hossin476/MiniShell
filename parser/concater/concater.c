#include "../../include/minishell.h"

void ft_free_garbage(t_lsttoken *item, char *str1, char *str2)
{
	free(str1);
	free(str2);
	free(item);
}

int ft_link_nodes(t_lsttoken *item)
{
	t_lsttoken *item2;
	char *tmp1;
	char *tmp2;

	if ((item->token & (tk_word | tk_sl_qt)) && item->next &&
	((item->next->token & (tk_word | tk_sl_qt))))
	{
		tmp1 = item->str;
		tmp2 = item->next->str;
		item->str = ft_strjoin(tmp1, tmp2);
		item2 = item->next;
		item->next = item->next->next;
		item->token = tk_word;
		ft_free_garbage(item2, tmp1, tmp2);
		return (1);
	}
	return (0);
}

void concate_cmd(t_lsttoken **head)
{
	t_lsttoken *item;

	if (!*head)
		return;
	item = *head;
	while (item)
	{
		if (item->token == tk_l_her)
			item = item->next->next;
		else if (ft_link_nodes(item))
			item = *head;
		else
			item = item->next;
	}
}

void ft_concate_redir(t_lsttoken **head)
{
	t_lsttoken *item;
	t_lsttoken *item2;
	char *tmp1;
	char *tmp2;

	concate_cmd(head);
	item = *head;
	while (item)
	{
		if ((item->token & (tk_exp | tk_word | tk_sl_qt | tk_db_qt | tk_joined)) && item->next && ((item->next->token & (tk_exp | tk_word | tk_sl_qt | tk_db_qt | tk_joined))))
		{
			tmp1 = item->str;
			tmp2 = item->next->str;
			item->str = ft_strjoin(tmp1, tmp2);
			item2 = item->next;
			item->next = item->next->next;
			item->token = tk_joined;
			ft_free_garbage(item2, tmp1, tmp2);
			item = *head;
		}
		else
			item = item->next;
	}
}

t_cmdlst *ft_concater(t_cmdlst *head)
{
	t_lsttoken *item;
	t_cmdlst *cmd;

	cmd = head;
	while (cmd)
	{
		item = cmd->cmd;
		concate_cmd(&item);
		item = cmd->redir;
		ft_concate_redir(&item);
		cmd = cmd->next;
	}
	return (head);
}
