/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:17 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:18 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_quotes_len(char *line, char c)
{
	int	i;

	i = 0;
	while (*line != '\0' && *line != c)
	{
		i++;
		line++;
	}
	return (i);
}

static int	check_qt(char *line, char c)
{
	int	bol;

	bol = 0;
	while (*line)
	{
		if (*line == c)
			bol = 1;
		line++;
	}
	return (bol);
}

int	ft_get_quotes(char **str, char **line)
{
	if (!check_qt((*line) + 1, **line))
	{
		if (**line == '\'')
			*str = ft_strdup("\'");
		else
			*str = ft_strdup("\"");
		*line += ft_strlen(*line);
		return (tk_op_qt);
	}
	if (**(line) == '\"')
	{
		*str = ft_substr(*line, 1, ft_quotes_len(*(line) + 1, '\"'));
		*line += ft_strlen(*str) + 2;
		return (tk_db_qt);
	}
	else
	{
		*str = ft_substr(*(line), 1, ft_quotes_len(*(line) + 1, '\''));
		*line += ft_strlen(*str) + 2;
		return (tk_sl_qt);
	}
}

int	is_var(char c)
{
	if (ft_isalpha(c) || c == '_' || c == '?')
		return (1);
	return (0);
}

int	ft_get_var(char **str, char **line)
{
	int		len;
	char	*s;

	s = *line + 1;
	len = 0;
	if (*s == '?')
	{
		len++;
		*str = ft_substr(*line, 0, len + 1);
		*line += len + 1;
		return (tk_exp);
	}
	while ((*s) && (ft_isalpha(*s) || ft_isalnum(*s) || *s == '_'))
	{
		len++;
		s++;
	}
	*str = ft_substr(*line, 0, len + 1);
	*line += len + 1;
	return (tk_exp);
}
