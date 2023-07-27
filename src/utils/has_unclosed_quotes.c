/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_unclosed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:38:21 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/26 20:06:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_unclosed_quotes(char *input)
{
	if (input == NULL)
		return (TRUE);
	while (*input != '\0')
	{
		if (*input == SINGLE_QUOTE)
		{
			input = ft_strchr(input + 1, SINGLE_QUOTE);
			if (input == NULL)
				return (TRUE);
		}
		else if (*input == DOUBLE_QUOTE)
		{
			input = ft_strchr(input + 1, DOUBLE_QUOTE);
			if (input == NULL)
				return (TRUE);
		}
		input++;
	}
	return (FALSE);
}

t_bool	is_quotes(char c)
{
	return ((c == SINGLE_QUOTE || c == DOUBLE_QUOTE));
}

int	input_is_delimiter(char *s1, char *s2)
{
	int	a;
	int	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a != b)
		return (FALSE);
	if (ft_strncmp(s1, s2, a + b) == 0)
		return (TRUE);
	return (FALSE);
}
