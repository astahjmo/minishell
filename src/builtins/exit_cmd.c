/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/09 14:35:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_cmd(t_databus *data, char *prompt)
{
	ft_putstr_fd("exit\n", 1);
	free_cmds(data->cmds);
	free(data->stream);
	free(prompt);
	exit(0);
}
