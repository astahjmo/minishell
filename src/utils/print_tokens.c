/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:00:25 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/27 15:25:52 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	print_tokens(void)
{
	t_databus	*data;
	t_node		*cursor;

	data = getter_data();
	cursor = data->cmds->head;
	while (cursor)
	{
		if (cursor->str && *cursor->str != '\0')
			ft_printf("[%s]\n", cursor->str);
		else
			ft_printf("[%s]\n", get_token_string(cursor->token));
		cursor = cursor->next;
	}
}

void	print_tokens_in_arr(t_node **cmds)
{
	t_node	*cursor;
	int		i;

	i = 0;
	while (cmds[i])
	{
		cursor = cmds[i];
		printf("Command arr: %d\n", i);
		while (cursor)
		{
			printf("[%s]:\n", cursor->str);
			cursor = cursor->next;
		}
		i++;
	}
}
