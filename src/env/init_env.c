/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:19:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/13 16:26:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_databus *data)
{
	int		i;
	char	**envp;

	i = -1;
	envp = data->envp;
	data->number_of_envs = 0;
	while (envp[data->number_of_envs] != NULL)
		data->number_of_envs++;
	if (data->number_of_envs < HEAP_OVERFLOW_PROTECTION)
	{
		while (++i < data->number_of_envs)
		{
			data->env[i] = ft_strdup(envp[i]);
			if (data->env[i] == NULL)
				break ;
		}
	}
}

void	free_env(t_databus *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_envs)
		if (data->env[i])
			free(data->env[i]);
}
