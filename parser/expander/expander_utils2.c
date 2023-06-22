#include "../../include/minishell.h"

int	ft_str_exp(char *str)
{
	int	len;

	len = 0;
	while (*str && *str != '$')
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_white_space(char **str, char **line)
{
	char	*wt;
	int		i;

	wt = *line;
	i = 0;
	while (*wt && (*wt == ' ' || *wt == '\t'))
	{
		wt++;
		i++;
	}
	*str = ft_substr(*line, 0, i);
	*line += i;
	return (tk_wt_s);
}

int	word_len(char *str)
{
	int	len;

	len = 0;
	if (*str == '$')
	{
		str++;
		len++;
	}
	while (*str && *str != ' ' && *str != '\t' && *str != '$')
	{
		len++;
		str++;
	}
	return (len);
}

int	get_word(char **str, char **line)
{
	*str = ft_substr(*line, 0, word_len(*line));
	*line += ft_strlen(*str);
	return (tk_word);
}

t_lsttoken	*tokinze_db_word(char *line)
{
	t_lsttoken	*head;
	t_lsttoken	*item;

	head = NULL;
	if (line == NULL)
		return (NULL);
	while (*line)
	{
		item = ft_lst_new();
		if (*line == ' ' || *line == '\t')
			item->token = ft_white_space(&item->str, &line);
		else if (*line == '$' && is_var(*(line + 1)))
			item->token = ft_get_var(&item->str, &line);
		else
			item->token = get_word(&item->str, &line);
		ft_lstaddback(&head, item);
	}
	return (head);
}
