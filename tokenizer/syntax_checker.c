/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:21 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:22 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid_redire(t_lsttoken *item)
{
	if ((item->token & (tk_l_dir | tk_r_dir | tk_l_her | tk_r_her))
		&& (item->next)
		&& !(item->next->token & (tk_exp | tk_sl_qt | tk_db_qt | tk_word)))
		return (0);
	return (1);
}

int	is_valid_pipe(t_lsttoken *tokens)
{
	if (tokens->token == tk_pipe && (tokens->next)
		&& !(tokens->next->token & (tk_l_dir | tk_r_dir | tk_l_her | tk_r_her))
		&& !(tokens->next->token & (tk_exp | tk_sl_qt | tk_db_qt | tk_word)))
		return (0);
	return (1);
}

int	is_tokens(t_lsttoken *tokens)
{
	if (tokens->token & (tk_pipe | tk_l_dir | tk_r_dir | tk_l_her | tk_r_her))
		return (1);
	return (0);
}

int	ft_check_pipe(t_lsttoken *tokens)
{
	if (tokens->token == tk_pipe)
		return (printf("syntax error near to %s\n", tokens->str),
			g_globs.g_exit_status = 258,
			1);
	return (0);
}

int	syntax_checker(t_lsttoken *tokens)
{
	if (!tokens)
		return (0);
	if (ft_check_pipe(tokens))
		return (0);
	while (tokens)
	{
		if (tokens->token == tk_op_qt)
			return (printf("syntax error open %s\n", tokens->str),
				g_globs.g_exit_status = 258, 0);
		else if (!is_valid_redire(tokens))
			return (printf("syntax error near to %s\n", tokens->str),
				g_globs.g_exit_status = 258, 0);
		else if (!is_valid_pipe(tokens))
			return (printf("syntax error near to %s\n", tokens->str),
				g_globs.g_exit_status = 258, 0);
		else if (tokens->next == NULL)
		{
			if (is_tokens(tokens))
				return (printf("syntax error near to %s\n", tokens->str),
					g_globs.g_exit_status = 258, 0);
		}
		tokens = tokens->next;
	}
	return (1);
}
