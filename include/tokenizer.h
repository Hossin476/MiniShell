#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

typedef enum s_token
{
	tk_word = 1 << 0,
	tk_pipe = 1 << 1,
	tk_db_qt = 1 << 3,
	tk_sl_qt = 1 << 4,
	tk_op_qt = 1 << 5,
	tk_wt_s = 1 << 6,
	tk_l_dir = 1 << 7,
	tk_r_dir = 1 << 8,
	tk_l_her = 1 << 9,
	tk_r_her = 1 << 10,
	tk_exp = 1 << 11,
	tk_joined = 1 << 12,
}	t_token;

typedef struct s_lsttoken
{
	t_token				token;
	char				*str;
	struct s_lsttoken	*next;
}						t_lsttoken;

t_lsttoken	*ft_tokenize(char *line);
void		ft_lstaddback(t_lsttoken **lst, t_lsttoken *new);
t_lsttoken	*ft_lst_new(void);
int			syntax_checker(t_lsttoken *tokens);
void		rm_node(t_lsttoken *node);
void		ft_rm_spaces(t_lsttoken *header);
int			is_var(char c);
int			ft_get_var(char **str, char **line);
t_lsttoken	*ft_tokenize(char *line);
void		ft_lstaddback(t_lsttoken **lst, t_lsttoken *new);
t_lsttoken	*ft_lst_new(void);
int			syntax_checker(t_lsttoken *tokens);
void		rm_node(t_lsttoken *node);
void		ft_rm_spaces(t_lsttoken *header);
int			is_var(char c);
int			ft_get_var(char **str, char **line);
int			ft_get_quotes(char **str, char **line);
int			ft_get_pipe(char **str, char **line);
int			ft_get_wt(char **str, char **line);
int			ft_get_redir(char **str, char **line);
int			ft_get_word(char **str, char **line);

#endif
