/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:38:21 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 18:26:57 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

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

t_bool	has_unclosed_quotes(char *line)
{
	int	single_quotes;
	int	double_quotes;
	int	i;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 39)
		{
			if (double_quotes == 0)
				single_quotes++;
		}
		else if (line[i] == 34)
			if (single_quotes == 0)
				double_quotes++;
		i++;
	}
	if ((single_quotes % 2) || (double_quotes % 2))
	{
		ft_printf("Error: Unclosed quotes in the string.\n");
		return (TRUE);
	}
	return (FALSE);
}

t_bool	is_quotes(char c)
{
	return ((c == 39 || c == 34));
}
