/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:31:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static t_tokens	get_token_from_arr(char *to_find, int arr_size, char **arr)
{
	int	idx;

	idx = 0;
	while (idx < arr_size && arr[idx] != NULL)
	{
		if (arr == get_operators_lexemes())
		{
			if (FALSE == ft_strncmp(to_find, arr[idx], ft_strlen(arr[idx])))
				return (idx + 1);
		}
		else if (arr == get_builtins_arr())
		{
			if (FALSE == ft_strcmp(to_find, arr[idx]))
				return (idx);
		}
		idx++;
	}
	return (T_INVALID);
}

t_tokens	get_token(char *line)
{
	t_ushort	arr_size;
	char		**operators_lexemes_arr;

	arr_size = 8;
	operators_lexemes_arr = get_operators_lexemes();
	return (get_token_from_arr(line, arr_size, operators_lexemes_arr));
}

t_tokens	is_builtin(char *cmd)
{
	t_ushort	arr_size;
	char		**builtins_arr;

	arr_size = 7;
	builtins_arr = get_builtins_arr();
	return (get_token_from_arr(cmd, arr_size, builtins_arr));
}
