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

void	unset_builtin(t_databus *data, char *env_to_unset)
{
	int	len;

	len = ft_strlen(env_to_unset);
	if (!len)
		return ;
	if (!ft_strncmp(data->env[data->number_of_envs - 1], env_to_unset, len + 1))
		return ;
	free(data->env[data->number_of_envs - 1]);
	data->env[data->number_of_envs - 1] = NULL;
	data->number_of_envs--;
}
