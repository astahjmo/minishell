/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:11:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/24 15:47:34 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_type(char *lexeme, char *type)
{
	char	**aux;
	int		idx;

	idx = -1;
	aux = ft_split(type, ' ');
	while (aux[++idx] != NULL)
		if (ft_strncmp(lexeme, aux[idx],
				ft_strlen(lexeme) + ft_strlen(aux[idx])) == 0)
			return (idx);
	return (-1);
}

t_tokens	get_token(char *lexeme)
{
	t_tokens	token;

	token.type = get_type(lexeme, TOKENS);
	token.word = lexeme;
	return (token);
}
