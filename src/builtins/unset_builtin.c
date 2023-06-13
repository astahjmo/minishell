/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:59:29 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/10 18:59:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_builtin(t_databus *data)
{
	int	len;
	char *env_to_unset;
	int	i;

	i = -1;
	env_to_unset = data->cmds->head->next->data;
	len = ft_strlen(env_to_unset);
	if (!len)
		return ;
	while (++i < data->number_of_envs)
	{
		if (data->env[i] && data->env[i][len] == '=')
			if (!ft_strncmp(data->env[i], env_to_unset, len))
				break ;
	}
	if (i == data->number_of_envs)
		return ;
	free(data->env[i]);
	data->env[i] = NULL;
}
