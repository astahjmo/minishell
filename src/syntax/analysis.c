/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:10:41 by astaroth          #+#    #+#             */
/*   Updated: 2023/07/28 18:04:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	invalid_syntax_err_msg(char *s)
{
	char	*str;

	str = fmt_s("minishell: %s\n", s, 0, 0);
	getter_data()->exit_status = 2;
	ft_putstr_fd(str, STDERR_FILENO);
	free(str);
}

static int	is_valid(t_tokens next)
{
	if (next == T_INPUT_REDIR || next == T_O_OUT_REDIR || next == T_HERE_DOC
		|| next == T_OUT_REDIR)
		return (1);
	if (next == T_SPACE)
		return (1);
	return (-1);
}

static int	is_operator(t_tokens token)
{
	return (token > T_INITIAL && token <= T_OUT_REDIR);
}

static int	get_next_state(t_tokens state, t_node *next)
{
	int			next_state;
	int			next_token;
	int			status;
	t_recipes	**recipes;

	recipes = init_recipes();
	status = -1;
	next_token = -1;
	if (state == T_INITIAL && is_operator(next->token)
		&& is_valid(next->token) == -1)
		return (-1);
	if (next == NULL && is_operator(state))
		return (-1);
	if (next)
		next_token = next->token;
	if (is_operator(next_token))
		next_state = 1;
	else
		next_state = 0;
	status = recipes[is_operator(state)](next_state);
	if (state == T_PIPE && next_token != T_WORD && status != T_SPACE)
		status = is_valid(next_token);
	return (status);
}

int	is_valid_syntax(t_node *head)
{
	t_tokens	state;
	int			progress;
	t_node		*cursor;
	char		*s;

	state = T_INITIAL;
	cursor = head;
	progress = get_next_state(state, cursor);
	while (cursor && progress != -1)
	{
		state = cursor->token;
		progress = get_next_state(state, cursor->next);
		if (progress == T_INVALID)
			break ;
		cursor = cursor->next;
	}
	if (progress != T_INVALID)
		return (TRUE);
	s = fmt_s(SYNTAX_ERR_MSG, get_token_string(state), 0, 0);
	invalid_syntax_err_msg(s);
	free(s);
	return (FALSE);
}
