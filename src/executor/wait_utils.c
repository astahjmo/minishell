/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:46:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/19 15:03:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_all_child(int bkp_fd, pid_t pid)
{
	int	count;
	int	status;

	count = 0;
	while (count != getter_data()->cmds->idx)
	{
		wait(&status);
		getter_data()->exit_status = WEXITSTATUS(status);
		count++;
	}
	waitpid(pid, &status, 0);
	getter_data()->exit_status = WEXITSTATUS(status);
	close(bkp_fd);
}
