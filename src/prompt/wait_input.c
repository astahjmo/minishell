/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 00:45:20 by johmatos         ###   ########.fr       */
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
		if (!data.stream)
		{
			ft_printf("\n");
			free(data.stream);
			free(prompt);
			exit(0);
		}
		else if (data.stream)
		{
			tokenizer(data);
			add_history(data.stream);
		}
		free(data.stream);
		free(prompt);
	}
	return (1);
}
