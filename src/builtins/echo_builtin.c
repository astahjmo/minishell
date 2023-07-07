/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:02:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/24 11:27:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_node *current)
{
	int	n_flag;

	n_flag = 0;
	if (current->next)
		current = current->next;
	while (current->next && !ft_strcmp("-n", current->next->str))
	{
		n_flag = 1;
		current = current->next;
	}
	while (current->next)
	{
		current = current->next;
		if (current->str)
			ft_printf(WHITE "%s" RESET, current->str);
	}
	if (!n_flag)
		ft_printf("\n");
}
