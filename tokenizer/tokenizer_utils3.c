#include "../include/minishell.h"

t_lsttoken	*ft_lst_new(void)
{
	t_lsttoken	*item;

	item = malloc(sizeof(t_lsttoken));
	if (!item)
		return (NULL);
	item->next = NULL;
	return (item);
}

void	ft_lstaddback(t_lsttoken **lst, t_lsttoken *new)
{
	t_lsttoken	*ptr;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}
