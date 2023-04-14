/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/14 19:38:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_input(t_databus data)
{
	char	*prompt;
	char	*here;

	while (TRUE)
	{
		ft_printf("prompt: ");
		data.stream = get_next_line(0);
		if (data.stream == NULL)
			exit(0);
		if (check_unclosed_quotes(data.stream, "\"") 
			|| check_unclosed_quotes(data.stream, "\'"))
		{
			here = here_doc(data.stream, "\"");
			data.type_stream = I_HERE_DOC;
		}
		else
			data.type_stream = I_COMMAND_LINE;
		free(data.stream);
	}
	return (1);
}
