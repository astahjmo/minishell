/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/05 18:48:47 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	get_set(char *line, int set_limits, char **set)
{
	int			idx;
	t_tokens	expansion;

	idx = 0;
	expansion = T_INVALID;
	while (idx < set_limits && expansion == T_INVALID)
	{
		if (ft_strncmp(line, set[idx],
				ft_strlen(set[idx]) + 1) == 0)
			expansion = idx + 1;
		idx++;
	}
	return (expansion);
}

t_tokens	get_expansion(char *line)
{
	return (get_set(line, 3, get_expansion_lexes()));
}

t_tokens	get_token(char *line)
{
	return (get_set(line, 8, get_lexemes()));
}
