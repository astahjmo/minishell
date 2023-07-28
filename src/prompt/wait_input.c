/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:03:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/28 18:05:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_syntax_err_msg(t_node *tmp)
{
	char	*s;

	s = fmt_s(SYNTAX_ERR_MSG, get_token_string(tmp->token), 0, 0);
	invalid_syntax_err_msg(s);
	free(s);
}

static void	if_stream_is_null(t_databus *data)
{
	if (!data->stream)
	{
		ft_putstr_fd("\n", 1);
		free_all(data);
		rl_clear_history();
		exit(0);
	}
}

static t_bool	has_empty_pipe(t_node *head)
{
	t_node	*tmp;
	t_bool	is_empty;

	tmp = head;
	is_empty = FALSE;
	while (tmp)
	{
		if (tmp->token == T_PIPE && (tmp->next && tmp->next->token == T_SPACE))
		{
			if (tmp->next->next && tmp->next->next->token == T_PIPE)
				is_empty = TRUE;
			else if (!tmp->next->next)
				is_empty = TRUE;
		}
		else if (tmp->token == T_OR_LOGIC)
			is_empty = TRUE;
		if (is_empty)
			break ;
		tmp = tmp->next;
	}
	if (is_empty)
		handle_syntax_err_msg(tmp);
	return (is_empty);
}

static void	if_stream_not_null(t_databus *data)
{
	if (*data->stream == '\0')
		return ;
	add_history(data->stream);
	if (has_unclosed_quotes(data->stream))
	{
		ft_printf("Error: Unclosed quotes in the string.\n");
		return ;
	}
	if (data->stream)
	{
		tokenizer();
		if (is_valid_syntax(data->cmds->head)
			&& !has_empty_pipe(data->cmds->head))
		{
			handle_expansions();
			retokenize();
			pre_executor(data);
			executor(data);
		}
		free_cmds(data->cmds);
	}
}

int	read_evaluate_print_loop(t_databus *data)
{
	char	*prompt;

	while (TRUE)
	{
		prompt = get_prompt();
		data->prompt = prompt;
		data->stream = readline(prompt);
		if_stream_is_null(data);
		if_stream_not_null(data);
		free(data->stream);
		free(prompt);
	}
	return (1);
}
