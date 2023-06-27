/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:01:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/25 08:58:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_node *current)
{
	char	cwd[STR_LIMIT];

	(void)current;
	printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

int	pwd_idx(void)
{
	t_databus	*data;
	int			i;

	i = 0;
	data = getter_data();
	while (i < data->number_of_envs)
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
			return (i);
		i++;
	}
	ft_strlcpy(data->env[data->number_of_envs], "PWD=", 5);
	return (data->number_of_envs);
}

int	oldpwd_idx(void)
{
	t_databus	*data;
	int			i;

	i = 0;
	data = getter_data();
	while (i < data->number_of_envs)
	{
		if (!ft_strncmp(data->env[i], "OLDPWD=", 7))
			return (i);
		i++;
	}
	ft_strlcpy(data->env[data->number_of_envs], "OLDPWD=", 7);
	return (data->number_of_envs);
}