/* ************************************************************************** */
// if_is_envcmd(data);
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:40:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/08 19:58:04 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(char *env[ENV_NAME_SZ], int number_of_envs)
{
	int	i;

	i = -1;
	while (++i < number_of_envs)
	{
		ft_putstr_fd(env[i], 1);
		ft_putchar_fd('\n', 1);
	}
}
