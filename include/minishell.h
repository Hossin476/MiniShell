#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include "env.h"
#include "builtin.h"
#include "tokenizer.h"
#include "cmdlist.h"
#include "expander.h"
#include "concater.h"
#include "here_doc.h"
#include "cmdexe.h"
#include "concater.h"
#include "env.h"
#include "executer.h"
#include "here_doc.h"
#include "tokenizer.h"
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct s_globals
{
    int g_exit_status;
    int g_flag;
} t_globals;

typedef struct s_minishell
{
    char *line;
    t_cmdexe *finalcmd;
    t_env *ENV;
    t_lstherdoc *item;
    int std_in;
    int std_out;
}   t_minishell;

t_globals globs;
int expand_db_word(char **str, t_env *env);
char *get_value(char *var, t_env *env);
void handle_signal(int sig);
void setup_signals(pid_t pid);
void ft_children(int signo);
void free_minishell(t_minishell *ms);
void init_minishell(t_minishell *ms, char **env);
void	handle_shlvl(t_env **ENV);
t_env *fill_env(char **ev);
void ft_freecdexe(t_cmdexe *head);
void ft_eof(char *line);
void ft_unlink_heredocs(t_lstherdoc *redir);
void ft_free_args(char **args);
int ft_check_heredoc(t_lstherdoc *item);
char *ft_join_key_val(const char *s1, const char *sep, const char *s2);
void clear_list(t_cmdlst *head);
char **env_to_array(t_env *env);
int ft_pars(char *line, t_env *ENV, t_cmdexe **finalcmd, t_lstherdoc **item);
#endif
