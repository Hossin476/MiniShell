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

void	handle_shlvl(t_env *ENV)
{
	char	*shlvl;
	int		lvl;
	char	*new_lvl;

	shlvl = get_env_value(ENV, "SHLVL");
	if (shlvl != NULL)
		lvl = ft_atoi(shlvl);
	else
		lvl = 1;
	lvl++;
	new_lvl = ft_itoa(lvl);
	ft_setenv(&ENV, "SHLVL", new_lvl);
	free(new_lvl);
}

void	init_minishell(t_minishell *ms, char **env)
{
	ms->line = NULL;
	ms->finalcmd = NULL;
	ms->ENV = fill_env(env);
	ms->item = NULL;
	ms->std_in = dup(STDIN_FILENO);
	ms->std_out = dup(STDOUT_FILENO);
}