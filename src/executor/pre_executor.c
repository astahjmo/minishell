/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:10:54 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:09:14 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_executor(t_databus *data)
{
	t_node	*head;
	int		status;

	status = 0;
	open_redir_io(getter_data()->cmds->head, getter_t_ios(), &status);
	if (WEXITSTATUS(status) == 129)
	{
		after_execution();
		return (status);
	}
	head = remove_operators(data->cmds->head);
	free_cmds(data->cmds);
	data->cmds->head = head;
	return (status);
}
