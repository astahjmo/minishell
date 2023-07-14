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

void	env_builtin(t_node *current)
{
	int			i;
	char		name[STR_LIMIT];
	char		content[STR_LIMIT];
	char		*s;
	t_databus	*data;

	i = -1;
	data = getter_data();
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(name, data->env[i]);
		get_env_content(content, name, data->env[i]);
		if (ft_strchr(data->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				s = fmt_s("%s=\n", name, NULL, NULL);
			else
				s = fmt_s("%s=%s\n", name, content, NULL);
			ft_putstr_fd(s, command_hook(data->cmds->idx)[OUT_FD]);
			free(s);
		}
	}
	after(current);
}

void	alt_env_builtin(t_node *current)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];
	char	*s;

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < getter_data()->number_of_envs)
	{
		get_env_name(name, getter_data()->env[i]);
		get_env_content(content, name, getter_data()->env[i]);
		if (ft_strchr(getter_data()->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				s = fmt_s("declare -x %s=\"\"\n", name, NULL, NULL);
			else
				s = fmt_s("declare -x %s=\"%s\"\n", name, content, NULL);
		}
		else
			s = fmt_s("declare -x %s\n", name, NULL, NULL);
		ft_putstr_fd(s, command_hook(getter_data()->cmds->idx)[OUT_FD]);
		free(s);
	}
	after(current);
}
