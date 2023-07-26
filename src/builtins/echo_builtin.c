/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:02:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/14 14:52:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_node *current)
{
	int	n_flag;
	int	cmd_io;

	n_flag = 0;
	cmd_io = getter_data()->cmds->idx;
	if (current->next)
		current = current->next;
	while (current && current->next && !ft_strcmp("-n", current->next->str))
	{
		n_flag = 1;
		current = current->next->next;
	}
	while (current && current->next)
	{
		current = current->next;
		if (current->str)
			ft_putstr_fd(current->str, command_hook(cmd_io)->output);
	}
	if (!n_flag)
		ft_putstr_fd("\n", command_hook(cmd_io)->output);
	getter_data()->exit_status = 0;
}
