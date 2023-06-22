/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:48 by lshail            #+#    #+#             */
/*   Updated: 2023/06/22 19:18:49 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**env_to_array(t_env *env)
{
	int		count;
	t_env	*cur_node;
	int		i;
	char	**env_arr;

	count = 0;
	i = 0;
	cur_node = env;
	while (cur_node != NULL)
	{
		count++;
		cur_node = cur_node->next;
	}
	env_arr = malloc(sizeof(char *) * (count + 1));
	cur_node = env;
	while (i < count)
	{
		env_arr[i] = ft_join_key_val(cur_node->key, "=", cur_node->value);
		cur_node = cur_node->next;
		i++;
	}
	env_arr[count] = NULL;
	return (env_arr);
}

char	*ft_join_key_val(const char *s1, const char *sep, const char *s2)
{
	size_t	s1_len;
	size_t	sep_len;
	size_t	s2_len;
	char	*result;

	s1_len = ft_strlen(s1);
	sep_len = ft_strlen(sep);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_len + sep_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, sep, sep_len);
	ft_memcpy(result + s1_len + sep_len, s2, s2_len);
	result[s1_len + sep_len + s2_len] = '\0';
	return (result);
}

void	handle_shlvl(t_env **envir)
{
	char	*shlvl;
	int		lvl;
	char	*new_lvl;
	t_env	*node;
	t_env	*new_node;

	node = get_env_node(*envir, "SHLVL");
	shlvl = get_env_value(*envir, "SHLVL");
	if (node == NULL)
	{
		new_node = ft_envnew();
		new_node->key = ft_strdup("SHLVL");
		new_node->value = ft_itoa(0);
		ft_add_env(envir, new_node);
	}
	if (shlvl != NULL)
		lvl = ft_atoi(shlvl);
	if (ft_atoi(shlvl) >= 1000)
		ft_putstr_fd("shell level too high, resetting to 1\n", 2);
	if (shlvl == NULL || ft_atoi(shlvl) >= 1000)
		lvl = 0;
	lvl++;
	new_lvl = ft_itoa(lvl);
	ft_setenv(envir, "SHLVL", new_lvl);
	free(new_lvl);
}

void	init_minishell(t_minishell *ms, char **env)
{
	ms->line = NULL;
	ms->finalcmd = NULL;
	ms->envir = fill_env(env);
	ms->item = NULL;
	ms->std_in = dup(STDIN_FILENO);
	ms->std_out = dup(STDOUT_FILENO);
}
