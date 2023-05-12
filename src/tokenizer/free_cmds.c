/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:55:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/12 02:13:42 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmds(t_cmds *cmds)
{
	t_node	*node;

	node = cmds->head;
    while (node->next != NULL)
    {
        node = node->next;
        free(node->back);
    }
	free(node);
	cmds->head = NULL;
}
