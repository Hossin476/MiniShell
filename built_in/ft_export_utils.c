/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:57 by lshail            #+#    #+#             */
/*   Updated: 2023/06/23 13:44:12 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**key_to_array(t_env *env)
{
	int		count;
	t_env	*temp;
	char	**keys;
	int		i;

	count = 0;
	temp = env;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	keys = malloc(sizeof(char *) * (count + 1));
	if(!keys)
		return (NULL);
	temp = env;
	i = 0;
	while (temp != NULL)
	{
		keys[i] = ft_valdup(temp->key);
		temp = temp->next;
		i++;
	}
	keys[i] = NULL;
	return (keys);
}

void	sort_array_of_keys(char **keys)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (keys[i])
	{
		j = i + 1;
		while (keys[j])
		{
			if (keys[j][0] < keys[i][0])
			{
				temp = keys[i];
				keys[i] = keys[j];
				keys[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_get_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_chars(char *line)
{
	int	i;

	i = 0;
	if (!*line || !line)
		return (0);
	while (line[i] == '_' || ft_isalpha(line[i]))
		i++;
	if (i == 0)
		return (0);
	while (line[i] == '_' || ft_isalpha(line[i]) || ft_isdigit(line[i]))
		i++;
	return (i);
}

int	ft_check_env(char *key)
{
	int	key_len;
	int	env_len;

	key_len = ft_strlen(key);
	env_len = ft_check_chars(key);
	if (key_len == env_len)
		return (1);
	else
		return (0);
}
