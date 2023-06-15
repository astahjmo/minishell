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

void	env_builtin(t_databus *d)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_bzero(content, STR_LIMIT);
	while (++i < d->number_of_envs)
	{
		get_env_name(d, name, d->env[i]);
		get_env_content(d, content, name);
		if (*content)
		{
			ft_putstr_fd(d->env[i], 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	alt_env_builtin(t_databus *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_envs)
	{
		if (data->env[i])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(data->env[i], 1);
			ft_putchar_fd('\n', 1);
		}
	}
}
