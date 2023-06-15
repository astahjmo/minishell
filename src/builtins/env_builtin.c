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
	ft_bzero(content, STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(data, name, data->env[i]);
		get_env_content(data, content, name);
		if (*content)
			printf("%s\n", data->env[i]);
	}
}

void	alt_env_builtin(t_databus *data)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	while (++i < data->number_of_envs)
	{
		get_env_name(data, name, data->env[i]);
		get_env_content(data, content, name);
		if (ft_strchr(data->env[i], '='))
			printf("declare -x %s=\"%s\"\n", name, content);
		else
			printf("declare -x %s\n", name);
	}
}
