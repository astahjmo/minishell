/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:36:16 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 00:36:19 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_setup_hook(t_databus *data)
{
	data->stream = NULL;
	data->type_stream = 0;
	data->cmds = malloc(sizeof(t_cmds));
	data->env = malloc(sizeof(t_env));
}
