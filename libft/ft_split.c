/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:42:12 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/02 17:27:52 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char *s, char *str)
{
	int	len;
	int	counter;

	counter = 0;
	len = 0;
	while (*s)
	{
		while (!ft_strchr(str,*s) && *s)
		{
			s++;
			counter++;
		}
		if (counter > 0)
		{
			counter = 0;
			len++;
		}
		if (!*s)
			break ;
		s++;
	}
	return (len);
}

static int	word_len(char *s, char *str)
{
	int	len;

	len = 0;
	while (*s && !ft_strchr(str,*s))
	{
		len++;
		s++;
	}
	return (len);
}

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static void	fill_split(char **split, char *s, char *str)
{
	int	wrd_len;
	int	i;

	i = 0;
	while (*s)
	{
		while (ft_strchr(str,*s) && *s)
			s++;
		if (!*s)
			break ;
		wrd_len = word_len((char *)s, str);
		split[i] = ft_substr(s, 0, wrd_len);
		if ((split[i]) == NULL)
		{
			free_split(split, i);
			return ;
		}
		s += wrd_len;
		i++;
	}
	split[i] = NULL;
}

char	**ft_split(char const *s, char *str)
{
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = word_counter((char *)s, str);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	fill_split(split, (char *)s, str);
	return (split);
}
