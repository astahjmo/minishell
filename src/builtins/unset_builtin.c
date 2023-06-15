/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:59:29 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/15 18:25:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			whole_prefix_matched(t_databus *data, int i, int len);
static int			getindex_of_env_to_unset(t_databus *data, int len, int n);

void	unset_builtin(t_databus *data)
{
	int		i;
	int		nb;
	char	*env_to_unset;
	t_node	*list;

	nb = data->number_of_envs;
	list = data->cmds->head;
	while (list)
	{
		env_to_unset = data->cmds->head->next->data;
		i = getindex_of_env_to_unset(data, ft_strlen(env_to_unset), nb);
		if (-1 == i)
			return ;
		while (i < nb)
		{
			ft_memmove(&data->env[i], &data->env[i + 1], STR_LIMIT);
			i++;
		}
		data->number_of_envs--;
		list = list->next;
	}
}

static int	getindex_of_env_to_unset(t_databus *data, int len, int n)
{
	int		i;
	char	*env_to_unset;

	i = -1;
	env_to_unset = data->cmds->head->next->data;
	if (!len)
		return (-1);
	while (++i < n)
	{
		if (!ft_strncmp(data->env[i], env_to_unset, len)
			&& whole_prefix_matched(data, i, len))
			break ;
	}
	if (i == n)
		return (-1);
	return (i);
}

static inline int	whole_prefix_matched(t_databus *data, int i, int len)
{
	return (data->env[i][len] == '=' || data->env[i][len] == '\0');
}
