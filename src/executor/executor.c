/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/10 17:48:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_databus *data)
{
	if (!ft_strncmp(data->stream, "exit", 5))
		exit_builtin(data);
	else if (!ft_strncmp(data->stream, "env", 4))
		env_builtin(data->env, data->number_of_envs);
	else if (!ft_strncmp(data->stream, "export ", 7))
		export_builtin(data, &data->stream[7]);
	else if (!ft_strncmp(data->stream, "export", 7))
		alt_env_builtin(data->env, data->number_of_envs);
	else if (!ft_strncmp(data->stream, "declare -x ", 11))
		export_builtin(data, &data->stream[11]);
	else if (!ft_strncmp(data->stream, "unset ", 6))
		unset_builtin(data, &data->stream[6]);
	return ;
}
