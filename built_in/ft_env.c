#include "../include/minishell.h"

t_env	*get_node(t_env *env)
{
	t_env	*cur_node;

	cur_node = NULL;
	if (env)
		cur_node = env;
	else if (cur_node && cur_node->next)
		cur_node = cur_node->next;
	return (cur_node);
}

int	ft_env_command(char **args, t_env *env)
{
	t_env	*cur_node;
	char	*key;
	char	*value;

	cur_node = NULL;
	if (strlen_double_ptr(args) != 1)
	{
		ft_error_check("env", 0, 2);
		return (-1);
	}
	cur_node = get_node(env);
	while (cur_node)
	{
		key = cur_node->key;
		value = cur_node->value;
		if (value)
			printf("%s=%s\n", key, value);
		cur_node = cur_node->next;
	}
	free(cur_node);
	globs.g_exit_status = 0;
	return (0);
}
