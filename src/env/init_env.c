/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:19:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/09 13:22:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char *env[ENV_NAME_SZ], char **envp, t_databus data)
{
	int	i;

	i = -1;
	data.number_of_envs = 0;
	while (envp[data.number_of_envs] != NULL)
		data.number_of_envs++;
	i = -1;
	while (++i < data.number_of_envs)
		env[i] = ft_strdup(envp[i]);
}
