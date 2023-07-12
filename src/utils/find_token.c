/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/12 17:27:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static t_tokens	get_set(char *to_find, int arr_size, char **arr)
{
	int	idx;
	int	len;

	idx = 0;
	len = ft_strlen(to_find);
	while (idx < arr_size && arr[idx] != NULL)
	{
		if (ft_strncmp(to_find, arr[idx], len) == 0)
		{
			if (arr == get_lexemes())
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
	return (get_set(cmd, 7, get_builtins()));
}
