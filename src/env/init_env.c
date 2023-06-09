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

void	init_env(char env[ENV_NUMB][ENV_SIZE], char **envp)
{
	int	i;
	int	number_of_envs;

	i = -1;
	number_of_envs = 0;
	while (envp[number_of_envs] != NULL)
		number_of_envs++;
	i = -1;
	if (number_of_envs > ENV_NUMB / 2)
		number_of_envs = ENV_NUMB / 2;
	while (++i < number_of_envs)
		ft_strlcpy(env[i], envp[i], strlen(envp[i]) + 1);
}
