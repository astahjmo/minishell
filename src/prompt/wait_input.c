/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/16 17:40:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_input(t_databus data)
{
	char	*prompt;

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
			if (!sintax_analysis(data.cmds->head))
				free_cmds(data.cmds);
		}
		free(data.stream);
		free(prompt);
	}
	return (1);
}
