/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/24 15:57:19 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*skip_blank_space(char *stream)
{
	return (NULL);
}

void	scanner(t_databus data)
{
	char	*cursor;
	char	**tokens;

	tokens = ft_split(TOKENS, ' ');
	cursor = data.stream;
}
