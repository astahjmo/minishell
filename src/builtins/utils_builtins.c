/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:06:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/15 10:09:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline int	already_exists(t_databus *data)
{
	char		*env;
	char		*new_env;
	t_ushort	i;

	i = 0;
	new_env = data->cmds->head->next->data;
	while (i < data->number_of_envs)
	{
		env = data->env[i];
		if (ft_strncmp(env, new_env, ft_strlen(new_env)) == 0)
			return (1);
		i++;
	}
	return (0);
}

inline int	is_initialized(t_databus *data, int i)
{
	char	*new_env;
	char	*env;

	new_env = data->cmds->head->next->data;
	env = data->env[i];
	if (env[ft_strlen(new_env)] == '=')
		return (1);
	return (0);
}
