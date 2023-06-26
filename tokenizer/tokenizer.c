/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:08 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:09 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	clear_tokenizer(t_lsttoken *head)
{
	t_lsttoken	*lst;

	if (!head)
		return ;
	lst = head->next;
	while (lst)
	{
		free(head->str);
		free(head);
		head = lst;
		lst = lst->next;
	}
	free(head->str);
	free(head);
}

void	ft_handle_redires(char **line, t_token *token, char **str)
{
	if ((**line == '<' && *(*line + 1) != '<') || (**line == '>' && *(*line
				+ 1) != '>'))
		*token = ft_get_redir(str, line);
	else if ((**line == '<' && *(*line + 1) == '<') || (**line == '>' && *(*line
				+ 1) == '>'))
		*token = ft_get_redir(str, line);
}

t_lsttoken	*get_list(char *line)
{
	t_lsttoken	*head;
	t_lsttoken	*item;

	head = NULL;
	while (*line)
	{
		item = ft_lst_new();
		if (!item)
			return (clear_tokenizer(head), NULL);
		if (*line == '\"' || *line == '\'')
			item->token = ft_get_quotes(&item->str, &line);
		else if (*line == '|')
			item->token = ft_get_pipe(&item->str, &line);
		else if (*line == ' ' || *line == '\t')
			item->token = ft_get_wt(&item->str, &line);
		else if (*line == '$' && is_var(*(line + 1)))
			item->token = ft_get_var(&item->str, &line);
		else if (!ft_strchr(" \t\r\v\f|\'\"<>", *line))
			item->token = ft_get_word(&item->str, &line);
		else
			ft_handle_redires(&line, &(item->token), &(item->str));
		ft_lstaddback(&head, item);
	}
	return (head);
}

t_lsttoken	*ft_tokenize(char *line)
{
	t_lsttoken	*head;
	char		*tmp_line;
	char		*start;

	head = NULL;
	tmp_line = line;
	line = ft_strtrim(line, " ");
	start = line;
	free(tmp_line);
	if (line[0] == '\0')
		return (free(line), NULL);
	head = get_list(line);
	line = start;
	free(line);
	ft_rm_spaces(head);
	if (!syntax_checker(head))
	{
		clear_tokenizer(head);
		return (NULL);
	}
	return (head);
}
