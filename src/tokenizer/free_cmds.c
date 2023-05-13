/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:55:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/12 19:40:05 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmds(t_cmds *cmds)
{
	t_node	*node;
	t_node	*tmp;

	node = cmds->head;
	while (node->next != NULL)
	{
		node = node->next;
		tmp = node->back;
		free(tmp);
	}
	free(node);
	cmds->head = NULL;
}
