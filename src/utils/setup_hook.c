/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:36:16 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/16 14:05:14 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	initialize_env(t_infoenv *env)
{
	env->count = 0;
	env->colision = 0;
}

void	main_setup_hook(t_databus *data)
{
	data->stream = NULL;
	data->type_stream = 0;
	data->cmds = malloc(sizeof(t_cmds));
	data->env = malloc(sizeof(t_infoenv));
	initialize_env(data->env);
}
