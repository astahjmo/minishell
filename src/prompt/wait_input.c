/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/18 14:08:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	if_stream_is_null(t_databus *data)
{
	if (!data->stream)
	{
		ft_putstr_fd("\n", 1);
		free_all(data);
		rl_clear_history();
		exit(0);
	}
}

static inline void	if_stream_not_null(t_databus *data)
{
	if (*data->stream == '\0')
		return ;
	add_history(data->stream);
	if (has_unclosed_quotes(data->stream))
		return ;
	if (data->stream)
	{
		tokenizer();
		handle_expansions();
		retokenize();
		if (is_valid_syntax(data->cmds->head))
		{
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
