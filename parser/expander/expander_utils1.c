#include "../../include/minishell.h"

int	expand_db_word(char **str, t_env *env)
{
	t_lsttoken	*head;
	char		*tmp;

	head = tokinze_db_word(*str);
	tmp = *str;
	free(tmp);
	*str = expand_dbq(head, env);
	ft_free_token(head);
	return (tk_word);
}

int	ft_check_word(t_lsttoken *ptr, char **word)
{
	char	*tmp;

	if (ptr->token != tk_exp)
	{
		tmp = *word;
		*word = ft_strjoin(tmp, ptr->str);
		free(tmp);
		return (1);
	}
	return (0);
}

char	*expand_dbq(t_lsttoken *ptr, t_env *env)
{
	char	*word;
	char	*tmp;
	char	*value;

	word = ft_strdup("");
	while (ptr)
	{
		if (!ft_check_word(ptr, &word))
		{
			value = get_value(ptr->str + 1, env);
			if (!value)
				value = ft_strdup("");
			tmp = word;
			word = ft_strjoin(word, value);
			free(tmp);
			free(value);
		}
		ptr = ptr->next;
	}
	return (word);
}

void	ft_free_token(t_lsttoken *head)
{
	t_lsttoken	*item;

	if (!head)
		return ;
	item = head->next;
	while (item)
	{
		free(head->str);
		free(head);
		head = item;
		item = item->next;
	}
	free(head->str);
	free(head);
}

void	rm_wts_nodes(t_lsttoken **head)
{
	t_lsttoken	*item;

	if (!head || !*head)
		return ;
	item = *head;
	if (item->token == tk_wt_s)
	{
		*head = (*head)->next;
		free(item->str);
		free(item);
	}
	ft_rm_nodes(head);
}
