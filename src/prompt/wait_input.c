/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loe <loe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/21 14:13:20 by loe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

int	wait_input(t_databus data)
{
	char	*prompt;
	char	*here;

	while (TRUE)
	{
		prompt = get_prompt();
		data.stream = readline(prompt);
		if (data.stream == NULL)
			exit(0);
		if (check_unclosed_quotes(data.stream, "\'") ||
				check_unclosed_quotes(data.stream, "\""))
			ft_printf("Bad usage: unclosed quotes\n");
		else
			data.type_stream = I_COMMAND_LINE;
		single_quotes_handler(data.stream);
		add_history(data.stream);
		free(data.stream);
	}
	return (1);
}
