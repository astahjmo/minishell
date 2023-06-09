/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/08 16:32:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	if_stream_is_null(char *stream, t_databus *data)
{
	if (!stream)
	{
		ft_printf("\n");
		free(stream);
		free_all(data);
		exit(0);
	}
}

static inline void	if_stream_not_null(t_databus data)
{
	if (data.stream)
	{
		tokenizer(data);
		add_history(data.stream);
		if (sintax_analysis(data.cmds->head))
			ft_printf("Sintax invalida :C");
		else
			executor(&data);
		free_cmds(data.cmds);
	}
}

int	repl(t_databus data)
{
	char	*prompt;

	while (TRUE)
	{
		prompt = get_prompt();
		data.prompt = prompt;
		data.stream = readline(prompt);
		if_stream_is_null(data.stream, &data);
		if_stream_not_null(data);
		free(data.stream);
		free(prompt);
	}
	return (1);
}
