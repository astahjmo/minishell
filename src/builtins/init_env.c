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
	int		j;
	int		envlen;
	char	**envp;

	i = 0;
	j = 0;
	envp = data->envp;
	data->number_of_envs = 0;
	while (envp[data->number_of_envs] != NULL)
		data->number_of_envs++;
	if (data->number_of_envs >= ENVS_LIMIT)
	{
		while (data->number_of_envs >= ENVS_LIMIT)
			data->number_of_envs = data->number_of_envs / 2;
	}
	while (i < data->number_of_envs)
	{
		envlen = ft_strlen(envp[j]) + 1;
		if (envlen <= STR_LIMIT)
			ft_strlcpy(data->env[i++], envp[j++], envlen);
		else
			j++;
	}
	printf("%d\n", data->number_of_envs);
}
