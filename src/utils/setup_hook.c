/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:36:16 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/04 06:39:43 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_setup_hook(t_databus *data)
{
	data->stream = NULL;
	data->type_stream = 0;
	data->cmds = malloc(sizeof(t_cmds));
	data->cmds->head = NULL;
	data->cmds->exit_code = 0;
	data->cmds->arr_cmds = NULL;
	data->cmds->idx = 0;
}
