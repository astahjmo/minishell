/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/27 16:53:11 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tokens	get_set(char *to_find, int arr_size, char **arr)
{
	int	idx;

	idx = 0;
	while (idx < arr_size && arr[idx] != NULL)
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
	return (get_set(line, arr_size, get_expansion_lexes()));
}

t_tokens	get_token(char *line)
{
	t_ushort	arr_size;

	arr_size = 8;
	return (get_set(line, arr_size, get_lexemes()));
}

t_tokens	is_builtin(char *cmd)
{
	return (get_set(cmd, 5, get_builtins()));
}
