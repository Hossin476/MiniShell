#include "./include/minishell.h"

t_env	*fill_env(char **ev)
{
	t_env	*env;

	env = env_init(ev);
	ft_setenv(&env, "OLDPWD", NULL);
	return (env);
}

void	ft_clear_env(t_env **env)
{
	t_env	*temp;

	while (*env != NULL)
	{
		temp = *env;
		*env = (*env)->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	free_minishell(t_minishell *ms)
{
	if (ms->finalcmd)
		ft_freecdexe(ms->finalcmd);
	if (ms->item)
		ft_unlink_heredocs(ms->item);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	ms;

	(void)ac;
	(void)av;
	init_minishell(&ms, env);
	handle_shlvl(&ms.envir);
	handle_signal(0);
	while (1)
	{
		dup2(ms.std_in, 0);
		dup2(ms.std_out, 1);
		ms.line = readline("\033[32;1mMiniShell$: \033[0m ");
		if (ms.line && *ms.line != '\0')
			add_history(ms.line);
		handle_signal(0);
		ft_eof(ms.line);
		if (!ft_pars(ms.line, ms.envir, &ms.finalcmd, &ms.item))
			continue ;
		ft_execute_cmd(ms.finalcmd, &ms.envir);
		free_minishell(&ms);
	}
	ft_clear_env(&ms.envir);
	rl_clear_history();
}
