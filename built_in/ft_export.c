#include "../include/minishell.h"

void	export_append(t_env *env, char **value, char **key)
{
	t_env	*node;
	char	*tmp;
	char	*new_value;

	if (!*value || !*key)
		return ;
	node = get_env_node(env, *key);
	if (node != NULL)
	{
		tmp = node->value;
		if (tmp == NULL)
			tmp = ft_strdup("");
		new_value = ft_strjoin(tmp, *value);
		free(tmp);
		if (new_value == NULL)
			return ;
		node->value = new_value;
		free(*value);
		*value = ft_strdup(new_value);
	}
}

void	init_val(t_regex *reg, char *word)
{
	reg->bol = 0;
	reg->eq = ft_get_char(word, '=');
	reg->pl = ft_get_char(word, '+');
}

int	ft_exportable(char *key)
{
	t_regex	r;

	if (!ft_check_env(key) || !ft_check_chars(key))
	{
		init_val(&r, "");
		r.bol = -1;
		ft_error_check("export", key, 4);
		return (0);
	}
	return (1);
}

int	ft_regex(char *wd, t_env *env, char **key, char **value)
{
	t_regex	r;

	init_val(&r, wd);
	if ((r.eq == 0 && wd[1] == '+') || (r.pl == 0 && wd[1] != '=') || r.pl == 0)
	{
		r.bol = -1;
		ft_error_check("export", wd, 4);
		return (r.bol);
	}
	if (r.pl != -1 && r.eq != -1 && wd[r.pl + 1] == '=')
	{
		*key = ft_substr(wd, 0, r.pl);
		*value = ft_substr(wd, r.eq + 1, ft_strlen(wd) - r.eq - 1);
		return (export_append(env, value, key), r.bol);
	}
	else if (r.eq != -1)
	{
		*key = ft_substr(wd, 0, r.eq);
		*value = ft_substr(wd, r.eq + 1, ft_strlen(wd) - r.eq - 1);
	}
	else
		*key = ft_strdup(wd);
	if (!ft_exportable(*key))
		return (r.bol);
	return (r.bol);
}

int	ft_export_command(char **args, t_env **env)
{
	t_export_vars	vars;

	initialize_export_vars(args, *env, &vars);
	while (args[vars.i])
	{
		vars.key = NULL;
		vars.value = NULL;
		if (ft_regex(args[vars.i], *env, &vars.key, &vars.value) == -1)
		{
			vars.i++;
			continue ;
		}
		update_env_node(env, vars.key, vars.value);
		vars.i++;
	}
	return (vars.bol);
}
