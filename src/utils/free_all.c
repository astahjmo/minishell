/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:38:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/11 18:08:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_databus *data)
{
	free(data->cmds);
	free(data->stream);
	free(data->prompt);
	rl_clear_history();
}

void	free_cmds_arr(t_node **cmds)
{
	t_node	*cursor;
	int			i;
	t_node	*tmp;

	if (!cmds)
		return ;
	i = 0;
	while (cmds[i])
	{
		cursor = cmds[i];
		while (cursor)
		{
			tmp = cursor->next;
			free(cursor->str);
			free(cursor);
			cursor = tmp;
		}
		i++;
	}
	free(cmds);
}
