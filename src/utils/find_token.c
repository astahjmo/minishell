/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 11:06:45 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tokens	get_index(char *to_find, int arr_size, char **arr)
{
	int	idx;

	idx = 0;
	while (idx < arr_size)
	{
		if (ft_strncmp(to_find, arr[idx], ft_strlen(arr[idx])) == 0)
		{
			if (arr_size == 8)
				return (idx + 1);
			else
				return (idx);
		}
		idx++;
	}
	return (T_INVALID);
}

t_tokens	get_expansion(char *line)
{
	t_ushort	arr_size;

	arr_size = 3;
	return (get_index(line, arr_size, get_expansion_lexes()));
}

t_tokens	get_token(char *line)
{
	t_ushort	arr_size;

	arr_size = 8;
	return (get_index(line, arr_size, get_lexemes()));
}

t_tokens	is_builtin(t_databus *data)
{
	t_ushort	arr_size;
	t_tokens	index;
	t_node		*list;

	arr_size = 6;
	list = data->cmds->head;
	if (!list->data)
		return (T_INVALID);
	index = get_index(list->data, arr_size, get_builtins());
	if (2 == index && !list->next)
		index++;
	return (index);
}
