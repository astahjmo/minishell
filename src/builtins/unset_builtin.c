/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:59:29 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/26 21:42:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	getindex_of_env_to_unset(t_databus *data, char *env);

void	unset_builtin(t_node *current)
{
	int			i;
	int			nb;
	char		*new_env;
	t_databus	*data;

	data = getter_data();
	data->exit_status = 0;
	nb = data->number_of_envs;
	if (!is_valid_syntax(current))
		return ;
	while (current->next)
	{
		current = current->next;
		new_env = current->str;
		i = getindex_of_env_to_unset(data, new_env);
		if (is_being_initialized(new_env) || (T_INVALID == i))
			continue ;
		while (i < nb)
		{
			ft_memmove(&data->env[i], &data->env[i + 1], STR_LIMIT);
			i++;
		}
		data->number_of_envs--;
	}
}

static int	getindex_of_env_to_unset(t_databus *data, char *to_unset)
{
	int	i;
	int	len;
	int	nb;

	i = -1;
	len = ft_strlen(to_unset);
	nb = data->number_of_envs;
	if (!len)
		return (-1);
	while (++i < nb)
	{
		if (!ft_strncmp(data->env[i], to_unset, len))
		{
			if (whole_prefix_matched(i, len))
				break ;
		}
	}
	if (i == nb)
		return (-1);
	return (i);
}

int	whole_prefix_matched(int i, int len)
{
	t_databus	*data;

	data = getter_data();
	return (data->env[i][len] == '=' || data->env[i][len] == '\0');
}
