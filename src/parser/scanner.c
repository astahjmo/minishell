/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/08 21:51:48 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token(char *stream, int *offset)
{
	char	**token_list;
	int		idx;

	idx = 0;
	token_list = ft_split(TOKENS, ' ');
	while (token_list[idx] != NULL)
	{
		if (ft_strncmp(stream,
				 token_list[idx],
				 ft_strlen(token_list[idx])) == 0)
		{
			*offset += ft_strlen(token_list[idx]);
			return (idx);
		}
		idx++;
	}
	clear_bimatrix(token_list);
	return (-1);
}

void	scanner(t_databus data)
{
	char	*cursor;
	char	**tokens;
	int		idx;
	int		token;

	cursor = data.stream;
	idx = 0;
	while(data.stream[idx] != '\0')
	{
		token = get_token(data.stream, &idx);
		if (token == -1)
			idx++;
	}
}
