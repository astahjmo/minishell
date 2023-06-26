/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:55:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/05 17:50:10 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmds(t_cmds *cmds)
{
	t_node	*node;
	t_node	*tmp;

	node = cmds->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->str);
		free(tmp);
	}
	free(node);
	cmds->head = NULL;
}
