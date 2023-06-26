/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:19:01 by lshail            #+#    #+#             */
/*   Updated: 2023/06/23 19:28:33 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

typedef struct s_export_command_vars
{
	char	*key;
	char	*value;
	t_env	*node;
	int		i;
	int		bol;
}	t_export_vars;

typedef struct s_regex
{
	int		eq;
	int		pl;
	int		bol;
	t_env	*env;
}	t_regex;

typedef struct s_env_init
{
	t_env	*head;
	int		i;
}	t_env_init;

int		strlen_double_ptr(char **args);
int		ft_compare(char *s1, char *s2);
char	*get_env_value(t_env *env, char *key);
void	update_env_value(t_env *env, char *key, char *value);
int		ft_setenv(t_env **head, char *key, char *value);
int		ft_error_check(char *cmd, char *word, int status);
t_env	*get_node(t_env *env);
char	*ft_valdup(const char *s1);
int		ft_check_env(char *key);
char	**key_to_array(t_env *env);
void	sort_array_of_keys(char **keys);
void	ft_export_solo(t_env *env);
int		ft_regex(char *wd, t_env *env, char **key, char **value);
void	init_val(t_regex *reg, char *word);
int		ft_exportable(char **key);
int		ft_check_chars(char *line);
int		ft_get_char(char *str, char c);
void	ft_clearnode(t_env **env, char *key);
t_env	*get_first_node(t_env *env);
t_env	*get_env_node(t_env *env, char *key);
t_env	*ft_envnew(void);
void	ft_add_env(t_env **lst, t_env *new);
void	free_keys(size_t j, char **ptr);
void	add_env_node(t_env **env, char *key, char *value);
t_env	*get_env_node(t_env *env, char *key);
void	export_append(t_env *env, char **value, char **key);
void	update_env_node(t_env **env, char *key, char *value);
void	initialize_export_vars(char **args, t_env *env, t_export_vars *vars);
int		ft_exit_command(char **args, t_env *env);
int		ft_cd_command(char **args, t_env *env);
int		ft_export_command(char **args, t_env **env);
int		ft_unset_command(char **args, t_env **env);
int		ft_pwd_command(char **args, t_env *env);
int		ft_env_command(char **args, t_env *env);
int		ft_echo_command(char **args, t_env *env);

#endif
