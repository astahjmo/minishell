/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:38:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/21 14:38:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_databus *data)
{
	free_cmds(data->cmds);
	free(data->cmds);
	free(data->stream);
	free(data->prompt);
	rl_clear_history();
}
