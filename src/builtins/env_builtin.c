/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/09 16:26:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(char *env[ENV_CONTENT_SZ], int number_of_envs)
{
	int	i;

	i = -1;
	while (++i < number_of_envs)
	{
		ft_putstr_fd(env[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

void	alt_env_builtin(char *env[ENV_CONTENT_SZ], int number_of_envs)
{
	int	i;

	i = -1;
	while (++i < number_of_envs)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env[i], 1);
		ft_putchar_fd('\n', 1);
	}
}
