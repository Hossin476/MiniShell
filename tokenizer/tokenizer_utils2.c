/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:14 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:15 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_pipe(char **str, char **line)
{
	*str = ft_substr(*line, 0, 1);
	*line += ft_strlen(*str);
	return (tk_pipe);
}

int	ft_get_wt(char **str, char **line)
{
	int		len;
	char	*s;

	s = *line;
	len = 0;
	while (ft_strchr(" \t\r\v\f", *s))
	{
		s++;
		len++;
	}
	*str = ft_substr(*line, 0, 1);
	*line += len;
	return (tk_wt_s);
}

int	ft_get_redir(char **str, char **line)
{
	if (!ft_strncmp("<", *line, 1) && ft_strncmp("<<", *line, 2))
	{
		*str = ft_substr(*line, 0, 1);
		*line += ft_strlen(*str);
		return (tk_l_dir);
	}
	else if (!ft_strncmp(">", *line, 1) && ft_strncmp(">>", *line, 2))
	{
		*str = ft_substr(*line, 0, 1);
		*line += ft_strlen(*str);
		return (tk_r_dir);
	}
	else if (!ft_strncmp("<<", *line, 2))
	{
		*str = ft_substr(*line, 0, 2);
		*line += ft_strlen(*str);
		return (tk_l_her);
	}
	else
	{
		*str = ft_substr(*line, 0, 2);
		*line += ft_strlen(*str);
		return (tk_r_her);
	}
}

int	ft_get_word(char **str, char **line)
{
	int		i;
	char	*s;

	i = 0;
	s = *line;
	if (*s == '$')
	{
		s++;
		i++;
	}
	while (!ft_strchr(" \t\r\v\f|\'\"<>$", *s) && *s)
	{
		s++;
		i++;
	}
	*str = ft_substr(*line, 0, i);
	*line += ft_strlen(*str);
	return (tk_word);
}
