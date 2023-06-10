/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:44:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/10 17:50:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_builtin(t_databus *data, char *new_env)
{
	if (++data->number_of_envs < HEAP_OVERFLOW_PROTECTION)
		data->env[data->number_of_envs - 1] = ft_strdup(new_env);
}
