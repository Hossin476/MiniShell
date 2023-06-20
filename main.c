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
 
void handle_shlvl(t_env *ENV)
{
	char *shlvl;
	int lvl;

	shlvl = get_env_value(ENV, "SHLVL");
	if (shlvl != NULL)
		lvl = ft_atoi(shlvl);
	else
		lvl = 1;
	lvl++;
	char *new_lvl = ft_itoa(lvl);
	ft_setenv(&ENV, "SHLVL", new_lvl);
	free(new_lvl);
}

t_env *fill_env(char **ev)
{
	t_env *ENV;
	ENV = env_init(ev);
	ft_setenv(&ENV, "OLDPWD", NULL);
	return ENV;
}

int main(int ac, char **av, char **env)
{
	char *line;
	t_cmdexe *finalcmd;
	t_env *ENV;
	t_lstherdoc *item;

	(void)ac;
	(void)av;
	ENV = fill_env(env);
	handle_shlvl(ENV);
	handle_signal(0);
	int std_in = dup(STDIN_FILENO);
	int std_out = dup(STDOUT_FILENO);
	while (1)
	{
		dup2(std_in, 0);
		dup2(std_out, 1);
		line = readline("\033[32;1mMiniShell$: \033[0m ");
		if (line && *line != '\0')
			add_history(line);
		handle_signal(0);
		ft_eof(line);
		if (!ft_pars(line, ENV, &finalcmd, &item))
			continue;
		ft_execute_cmd(finalcmd, ENV);
		ft_unlink_heredocs(item);
		ft_freecdexe(finalcmd);
	}
	free(ENV);
}
