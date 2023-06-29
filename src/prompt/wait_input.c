/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/27 15:45:24 by johmatos         ###   ########.fr       */
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
	if (data->stream)
	{
		tokenizer();
		add_history(data->stream);
		expand_dollar_question_of_all_cmds();
		expand_dollar_env_of_all_cmds();
		if (is_valid_syntax(data->cmds->head))
		{
			create_new_cmds_list();
			executor(data);
		}
		free_cmds(data->cmds);
	}
}

int	repl(t_databus *data)
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
