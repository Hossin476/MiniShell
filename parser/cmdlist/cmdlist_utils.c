#include "../../include/minishell.h"

t_cmdlst *new_cmd(void)
{
	t_cmdlst *item;

	item = malloc(sizeof(t_cmdlst));
	if (!item)
		return (NULL);
	item->next = NULL;
	item->cmd = NULL;
	item->redir = NULL;
	return (item);
}

void lst_add_cmd_back(t_cmdlst *cmd, t_cmdlst **headcmd)
{
	t_cmdlst *ptr;

	if (!cmd || !headcmd)
		return;
	if (*headcmd == NULL)
	{
		*headcmd = cmd;
		return;
	}
	ptr = *headcmd;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = cmd;
}

void ft_lstadd_cmd(t_lsttoken **lst, t_lsttoken *new, t_lsttoken **head)
{
	t_lsttoken *ptr;

	if (!lst)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		*head = (*head)->next;
		new->next = NULL;
		return;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	*head = (*head)->next;
	new->next = NULL;
}

int is_redir(t_lsttoken *item)
{
	if (item->token == tk_l_dir || item->token == tk_r_dir ||
	item->token == tk_l_her || item->token == tk_r_her)
		return (1);
	return (0);
}

int is_cmd(t_lsttoken *item)
{
	if (item && (item->token == tk_wt_s || item->token == tk_word ||
	item->token == tk_db_qt || item->token == tk_sl_qt || item->token == tk_exp))
		return (1);
	return (0);
}