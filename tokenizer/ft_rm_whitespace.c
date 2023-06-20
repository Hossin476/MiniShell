
#include "../include/minishell.h"


void rm_node(t_lsttoken *node)
{

	t_lsttoken *tmp;

	tmp = node->next;
	node->next = tmp->next;
	tmp->next = NULL;
	free(tmp->str);
	free(tmp);
}

static int is_valid_word(t_lsttoken *item)
{
	if (item && (item->token & (tk_exp|tk_sl_qt|tk_db_qt|tk_word))
			&& (item->next) && (item->next->token == tk_wt_s)
		 	&& (item->next->next)
			&& (item->next->next->token & (tk_exp|tk_sl_qt|tk_db_qt|tk_word)))
			return (1);
	return (0);
}

static int is_removeable(t_lsttoken * item)
{
	if((item->token != tk_wt_s) && item->next
		&& item->next->token == tk_wt_s && item->next->next
		&&(item->next->next->token != tk_wt_s))
		return(1);
	return(0);
}

void ft_rm_spaces(t_lsttoken *header)
{
	t_lsttoken *item;
	
	if(!header)
		return;
	item = header;
	while (item->next)
	{
		if (is_valid_word(item))
			item = item->next;
		else if(is_removeable(item))
		{
			rm_node(item);
			item = header;
		}
		else
			item = item->next;
	}
}
