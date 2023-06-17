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
static int			getindex_of_env_to_unset(t_databus *data, char *env, int n);

void	unset_builtin(t_databus *data)
{
	int		i;
	int		nb;
	t_node	*list;

	nb = data->number_of_envs;
	list = data->cmds->head->next;
	while (list)
	{
		if (is_being_initialized(list->data))
		{
			list = list->next;
			continue ;
		}
		i = getindex_of_env_to_unset(data, list->data, nb);
		if (-1 == i)
			return ;
		while (i < nb)
		{
			ft_memmove(&data->env[i], &data->env[i + 1], STR_LIMIT);
			i++;
		}
		list = list->next;
		data->number_of_envs--;
	}
}

static int	getindex_of_env_to_unset(t_databus *data, char *to_unset, int nb)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(to_unset);
	if (!len)
		return (-1);
	while (++i < nb)
	{
		if (!ft_strncmp(data->env[i], to_unset, len)
			&& whole_prefix_matched(data, i, len))
			break ;
	}
	if (i == nb)
		return (-1);
	return (i);
}

static inline int	whole_prefix_matched(t_databus *data, int i, int len)
{
	return (data->env[i][len] == '=' || data->env[i][len] == '\0');
}
