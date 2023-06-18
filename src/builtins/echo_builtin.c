/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:02:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/18 15:02:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_databus *data)
{
	int		n_flag;
	t_node	*list;

	n_flag = 0;
	list = data->cmds->head;
	if (list->next && !ft_strncmp(list->next->data, "-n", 2))
	{
		n_flag = 1;
		list = list->next;
	}
	while (list->next)
	{
		list = list->next;
		ft_putstr_fd(list->data, 1);
		if (list->next)
			write(1, " ", 1);
	}
	if (!n_flag)
		write(1, "\n", 1);
}
