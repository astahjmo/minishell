/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:19:40 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 04:58:20 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "global.h"

void	sintax_analysis(t_node *head)
{
	int			state;
	t_tokens	token;
	t_node		*cursor;

	cursor = head;
	state = T_INITIAL;
	while (cursor && state != -1)
	{
		token = cursor->token;
		state = g_machine[state][token];
		cursor = cursor->next;
	}

	if (state != -1 && cursor == NULL)
		ft_printf("acabo");
	else
		ft_printf("syntax");
}
