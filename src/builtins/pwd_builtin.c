/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:01:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/14 14:55:11 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_node *current)
{
	char	cwd[STR_LIMIT];
	int		cmd_count;

	cmd_count = getter_data()->cmds->idx;
	ft_putendl_fd(getcwd(cwd, sizeof(cwd)), command_hook(cmd_count)->output);
	set_ext_code_after_builtin(current);
}

int	get_pwd_idx(void)
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

int	get_oldpwd_idx(void)
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
