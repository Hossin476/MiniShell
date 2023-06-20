 
 #include "../../include/minishell.h"


int is_redir_word(t_lsttoken *item)
{
	if(item->token == tk_word || item->token == tk_db_qt
		|| item->token == tk_sl_qt || item->token == tk_exp)
		return (1);
	return (0);
}

void ft_check_cmds(t_cmdlst *headcmd)
{
	if(!headcmd)
		return;
	t_cmdlst *cmditem;
	t_lsttoken *item;

	cmditem = headcmd;
	while (cmditem)
	{
		item = cmditem->cmd;

		if(item && item->token == tk_wt_s)
		{
			cmditem->cmd = item->next;
			free(item->str);
			free(item);
		}
		cmditem = cmditem->next;
	}
}
void ft_handle_cmds(t_cmdlst **cmd,t_lsttoken **head)
{
	t_lsttoken *item;
	t_cmdlst *lcmd;

	lcmd = *cmd;
	item = *head;
	while (item && item->token!=tk_pipe)
		{
			while (item && is_cmd(item))
			{
				ft_lstadd_cmd(&lcmd->cmd,item,head);
				item = *head;
			}
			while (item && ( is_redir(item) || is_redir_word(item)))
			{
				ft_lstadd_cmd(&lcmd->redir,item,head);
				item = *head;
			}
		}
}

static void handlepipe(t_lsttoken **head, t_lsttoken **item)
{
	t_lsttoken * garbage;

	if (*item &&  (*item)->token == tk_pipe)
		{
			garbage = (*head);
			(*head) = (*head)->next;
			free(garbage->str);
			free(garbage);
			*item = (*head);
		}
}
t_cmdlst *get_cmdlist(t_lsttoken **head)
{
	t_lsttoken *item;
	t_cmdlst *headcmd;
	t_cmdlst *cmd;

	headcmd = NULL;
	cmd = NULL;
	if(!head || !*head)
		return (NULL);
	item = *head;
	while (item)
	{
		handlepipe(head, &item);
		cmd = new_cmd();
		ft_handle_cmds(&cmd,head);
		lst_add_cmd_back(cmd,&headcmd);
		item = *head;
	}
	ft_check_cmds(headcmd);
	return headcmd;
}
