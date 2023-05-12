/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:19:40 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 00:35:41 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "global.h"

void	sintax_analysis(t_node *head)
{
	int			state;
	t_tokens	token;
	t_node		*cursor;

	cursor = head;
	state = T_INITIAL;
	while (state != -1)
	{
		token = cursor->token;
		state = g_machine[state][token];
		cursor = cursor->next;
	}
}
