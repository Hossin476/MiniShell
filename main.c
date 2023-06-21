#include "./include/minishell.h"

void exedisplay(t_cmdexe *head)
{
	t_cmdexe *item;
	item = head;
	char **args;
	while (item)
	{
		printf("-----------\n");
		printf("args:");
		args = item->args;
		while (*args)
		{
			printf("%s:", *args);
			args++;
		}
		puts("");
		printf("input:%d\n", item->input);
		printf("output:%d\n", item->output);
		printf("error_log:%s\n", item->error_log);
		printf("------------\n");
		item = item->next;
	}
}

t_env *fill_env(char **ev)
{
	t_env *ENV;
	ENV = env_init(ev);
	ft_setenv(&ENV, "OLDPWD", NULL);
	return ENV;
}

void ft_clear_env(t_env **env)
{
	t_env *temp;

	while (*env != NULL)
	{
		temp = *env;
		*env = (*env)->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void free_minishell(t_minishell *ms)
{
	if (ms->finalcmd)
		ft_freecdexe(ms->finalcmd);
	if (ms->item)
		ft_unlink_heredocs(ms->item);
}


int main(int ac, char **av, char **env)
{
	t_minishell ms;

	(void)ac;
	(void)av;
	init_minishell(&ms, env);
	handle_shlvl(ms.ENV);
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
		if (!ft_pars(ms.line, ms.ENV, &ms.finalcmd, &ms.item))
			continue;
		ft_execute_cmd(ms.finalcmd, &ms.ENV);
		free_minishell(&ms);
	}
	ft_clear_env(&ms.ENV);
	rl_clear_history();
}
