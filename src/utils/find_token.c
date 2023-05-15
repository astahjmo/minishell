/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 17:37:23 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_tokens	get_token(char *line)
{
	int			idx;
	char		*beggin;
	char		*end;
	t_tokens	token;

	beggin = TOKENS;
	end = TOKENS;
	token = -1;
	idx = 1;
	while (token == (t_tokens)-1 && *beggin != '\0')
	{
		while (*end != ' ' && *end != '\0')
			end++;
		if (*beggin && *beggin != '\0'
			&& ft_strncmp(line, beggin, end - beggin) == 0)
			return (idx);
		while (*end == ' ' && *end != '\0')
			end++;
		beggin = end;
		idx++;
	}
	return (-1);
}
