/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/17 21:43:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_input(t_databus data)
{
	char	*prompt;
	char	*line;

	while (TRUE)
	{
		prompt = get_prompt();
		data.stream = readline(prompt);
		add_history(data.stream);
		if (data.stream == NULL)
		{
			ft_printf("exit\n");
			exit(1);
		}
		if (check_unclosed_quotes(data.stream, "\""))
		{
			here_doc(data.stream, "\"");
			data.type_stream = I_HERE_DOC;
		}
		else
			data.type_stream = I_COMMAND_LINE;
		scanner(data);
		free(prompt);
		free(data.stream);
	}
	return (1);
}
