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

void	env_builtin(t_databus *data)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(name, data->env[i]);
		get_env_content(content, name, data->env[i]);
		if (ft_strchr(data->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				printf("%s=\n", name);
			else
				printf("%s=%s\n", name, content);
		}
	}
}

void	alt_env_builtin(t_databus *data)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(name, data->env[i]);
		get_env_content(content, name, data->env[i]);
		if (ft_strchr(data->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				printf("declare -x %s=\"\"\n", name);
			else
				printf("declare -x %s=\"%s\"\n", name, content);
		}
		else
			printf("declare -x %s\n", name);
	}
}
